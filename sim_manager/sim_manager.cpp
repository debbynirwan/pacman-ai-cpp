/*
 * Copyright 2023 Debby Nirwan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "spdlog/spdlog.h"
#include "yaml-cpp/yaml.h"
#include <QApplication>
#include <iostream>
#include <stdexcept>

#include "agent_utils.h"
#include "pacman_factory.h"
#include "random_ghost_impl.h"
#include "sim_manager.h"

SimulationManager::SimulationManager(const std::string& layoutFile, const std::string& pacmanName,
                                     const bool autoExit)
    : m_agentImpls()
    , m_gameRules(layoutFile, "configs/configs.yaml")
    , m_tickTimer(nullptr)
    , m_display(display::MakeDisplay(display::DisplayType::GUI, m_gameRules.GetLayout()))
    , m_newWorldState(m_gameRules.GetCurrentWorldState())
    , m_agentActions()
    , m_autoExit(autoExit)
    , m_tickPeriod(0)
{
    spdlog::debug("Game created with:\n"
                  "pacman: {}\n"
                  "layout: {}\n"
                  "auto-exit: {}\n",
                  pacmanName, layoutFile, autoExit);

    auto initialWorldState = m_gameRules.GetCurrentWorldState();

    YAML::Node configs = YAML::LoadFile("configs/configs.yaml");
    m_tickPeriod = static_cast<unsigned int>(configs["configs"]["tick_period"].as<int>());

    m_agentImpls.insert({ 0, MakePacman(pacmanName) });
    if (m_agentImpls[0] == nullptr) {
        throw std::invalid_argument("Invalid Pacman name.");
    }

    for (const auto& [id, agent] : initialWorldState.ghosts) {
        m_agentImpls.insert({ id, std::make_shared<RandomGhostImpl>(false) });
    }

    m_tickTimer = new QTimer(this);   // NOLINT
    connect(m_tickTimer, SIGNAL(timeout()), this, SLOT(Tick()));

    m_display->Initialize(initialWorldState);
}

void SimulationManager::Start()
{
    spdlog::debug("Game started with tick: {} ms", m_tickPeriod);
    m_tickTimer->start(static_cast<int>(m_tickPeriod) / DISPLAY_TICK_MULTIPLIER);
}

void SimulationManager::Stop()
{
    spdlog::debug("Game stopped");
    m_tickTimer->stop();

    if (m_autoExit) {
        spdlog::debug("Automatically exiting...");
        QApplication::quit();
    }
}

void SimulationManager::Tick()
{
    static bool only_display = false;

    if (!only_display) {
        UpdateActions();
        m_newWorldState = m_gameRules.Tick(m_agentActions);
    }

    m_display->Tick(m_newWorldState, m_agentActions);

    if (Won() || Lost()) {
        Stop();
        return;
    }

    if (only_display)
        m_agentActions.clear();

    only_display = !only_display;
}

bool SimulationManager::Won() const
{
    if (m_newWorldState.gameState.won.has_value() && m_newWorldState.gameState.won.value()) {
        spdlog::info("Pac-man won");
        return true;
    }

    return false;
}

bool SimulationManager::Lost() const
{
    if (m_newWorldState.gameState.lost.has_value() && m_newWorldState.gameState.lost.value()) {
        spdlog::info("Pac-man lost");
        return true;
    }

    return false;
}

void SimulationManager::UpdateActions()
{
    for (auto& [id, agent_impl] : m_agentImpls) {
        auto action = agent_impl->GetAction(m_gameRules.GetCurrentWorldState(), id);
        m_agentActions.insert({ id, action });
    }
}
