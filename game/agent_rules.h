#pragma once

#include "yaml-cpp/yaml.h"
#include <string>

#include "agent.h"
#include "game_state.h"

class AgentRules {
public:
    AgentRules(const std::string& cfg)
    {
        YAML::Node configs = YAML::LoadFile(cfg);
        m_scaredTick = static_cast<std::size_t>(configs["configs"]["scared_tick"].as<int>());
        m_foodEatingScore
            = static_cast<std::size_t>(configs["configs"]["food_eating_score"].as<int>());
        m_movementCost = static_cast<std::size_t>(configs["configs"]["movement_cost"].as<int>());
    }

    virtual ~AgentRules() { }

    virtual void Tick(const std::size_t id, const Action& action, WorldState& worldState) = 0;

protected:
    std::size_t m_scaredTick;
    std::size_t m_foodEatingScore;
    std::size_t m_movementCost;

    void ResetGhostPos(const std::size_t id, WorldState& worldState);
};

class PacmanRules : public AgentRules {
public:
    PacmanRules(const std::string& cfg)
        : AgentRules(cfg)
    {
    }

    virtual void Tick(const std::size_t id, const Action& action, WorldState& worldState) override;

private:
    bool MaybeEatFood(WorldState& worldState);
    void MaybeEatCapsule(WorldState& worldState);
};

class GhostRules : public AgentRules {
public:
    GhostRules(const std::string& cfg)
        : AgentRules(cfg)
    {
    }

    virtual void Tick(const std::size_t id, const Action& action, WorldState& worldState) override;
};
