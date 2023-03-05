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
#pragma once

#include <QTimer>
#include <map>
#include <memory>

#include "agent_impl.h"
#include "display.h"
#include "game_rules.h"

class SimulationManager : public QObject {
    Q_OBJECT
public:
    SimulationManager(const std::string& layoutFile, const std::string& pacmanName,
                      const bool autoExit);
    void Start();
    void Stop();

public slots:
    void Tick();

private:
    std::map<std::size_t, std::shared_ptr<AgentImpl>> m_agentImpls;
    GameRules m_gameRules;
    QTimer* m_tickTimer;
    std::shared_ptr<display::DisplayInterface> m_display;
    WorldState m_newWorldState;
    std::map<std::size_t, Action> m_agentActions;
    bool m_autoExit;
    unsigned int m_tickPeriod;
    static constexpr int DISPLAY_TICK_MULTIPLIER = 2;

    bool Won() const;
    bool Lost() const;

    void UpdateActions();
};
