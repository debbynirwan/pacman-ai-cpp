#include "game_rules.h"

GameRules::GameRules(const std::string& layoutFile, const std::string& cfg)
    : m_worldState(layoutFile)
    , m_agentRules()
    , m_scaredTimerOn(false)
{
    m_agentRules.insert({ AgentType::PACMAN, std::make_shared<PacmanRules>(cfg) });
    m_agentRules.insert({ AgentType::GHOST, std::make_shared<GhostRules>(cfg) });
}

WorldState GameRules::Tick(const std::map<std::size_t, Action>& agentActions)
{
    UpdateScaredTimerAndStatus();

    for (const auto& [id, action] : agentActions) {
        auto type = (id == 0) ? AgentType::PACMAN : AgentType::GHOST;
        m_agentRules[type]->Tick(id, action, m_worldState);

        if (Lost())
            break;
    }

    MaybeWon();

    return m_worldState;
}

Layout GameRules::GetLayout() const { return m_worldState.layout; }

void GameRules::UpdateScaredTimerAndStatus()
{
    if (m_worldState.scaredTimer)
        m_worldState.scaredTimer--;

    if (!m_worldState.scaredTimer && m_scaredTimerOn) {
        for (auto& ghost : m_worldState.ghosts) {
            ghost.second.status = AgentStatus::NORMAL;
        }
    }
    m_scaredTimerOn = (m_worldState.scaredTimer != 0);
}

void GameRules::MaybeWon() { m_worldState.gameState.won = m_worldState.food.AllInitialValues(); }

bool GameRules::Lost()
{
    if (m_worldState.gameState.lost.has_value() && m_worldState.gameState.lost.value()) {
        return true;
    }

    return false;
}
