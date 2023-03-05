#pragma once

#include "agent.h"
#include "layout.h"
#include "point.h"
#include <iostream>
#include <map>
#include <optional>

struct GameState {
    GameState()
        : lost(std::nullopt)
        , won(std::nullopt)
        , score(0)
    {
    }

    std::optional<bool> lost;
    std::optional<bool> won;
    int score;
};

struct WorldState {
    WorldState(const std::string& layoutFile)
        : food(0, 0, false)
        , layout(layoutFile)
    {
        capsules = layout.Capsules();
        food = layout.Food();
        scaredTimer = 0;

        for (const auto& agent : layout.Agents()) {
            if (agent.type == AgentType::PACMAN) {
                pacman = agent;
            } else {
                ghosts.insert({ agent.id, agent });
            }
        }
    }

    Agent pacman;
    std::map<std::size_t, Agent> ghosts;
    std::vector<Point> capsules;
    Grid<bool> food;
    std::size_t scaredTimer;
    GameState gameState;
    Layout layout;
};

std::ostream& operator<<(std::ostream& os, const GameState& gameState);
