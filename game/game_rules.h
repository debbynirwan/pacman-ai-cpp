#pragma once

#include "agent.h"
#include "agent_rules.h"
#include "game_state.h"
#include <memory>

class GameRules {
public:
    GameRules(const std::string& layoutFile, const std::string& cfg);
    WorldState Tick(const std::map<std::size_t, Action>& agentActions);
    Layout GetLayout() const;

    WorldState GetCurrentWorldState() const { return m_worldState; }

private:
    WorldState m_worldState;
    std::map<AgentType, std::shared_ptr<AgentRules>> m_agentRules;
    bool m_scaredTimerOn;

    void UpdateScaredTimerAndStatus();
    void MaybeWon();
    bool Lost();
};
