#include "agent_rules.h"
#include "agent_utils.h"
#include <algorithm>

void AgentRules::ResetGhostPos(const std::size_t id, WorldState& worldState)
{
    auto agents = worldState.layout.Agents();
    auto ghost = std::find_if(agents.begin(), agents.end(), [id](const Agent& agent) {
        if (agent.id == id)
            return true;
        else
            return false;
    });

    if (ghost != agents.end()) {
        worldState.ghosts[id].point = ghost->point;
    }
}

void PacmanRules::Tick(const std::size_t id, const Action& action, WorldState& worldState)
{
    worldState.gameState.score -= m_movementCost;

    if (!std::holds_alternative<Stop>(action)) {
        auto new_pos = move(worldState.pacman.point, std::get<Direction>(action));

        if (worldState.layout.Walls().Get(new_pos.x, new_pos.y))
            return;

        worldState.pacman.point = new_pos;

        for (const auto& [id, ghost] : worldState.ghosts) {
            if (ghost.point == worldState.pacman.point) {
                if (ghost.status == AgentStatus::NORMAL)
                    worldState.gameState.lost = true;
                else
                    ResetGhostPos(id, worldState);
                break;
            }
        }

        if (!worldState.gameState.lost) {
            if (!MaybeEatFood(worldState))
                MaybeEatCapsule(worldState);
        }
    }
}

bool PacmanRules::MaybeEatFood(WorldState& worldState)
{
    if (worldState.food.Get(worldState.pacman.point.x, worldState.pacman.point.y)) {
        worldState.gameState.score += m_foodEatingScore;
        worldState.food.Set(worldState.pacman.point.x, worldState.pacman.point.y, false);
        return true;
    }

    return false;
}

void PacmanRules::MaybeEatCapsule(WorldState& worldState)
{
    for (auto capItr = worldState.capsules.begin(); capItr != worldState.capsules.end();) {
        if (*capItr == worldState.pacman.point) {
            worldState.scaredTimer = m_scaredTick;

            for (auto& [id, ghost] : worldState.ghosts)
                ghost.status = AgentStatus::SCARED;

            capItr = worldState.capsules.erase(capItr);
            break;
        } else {
            ++capItr;
        }
    }
}

void GhostRules::Tick(const std::size_t id, const Action& action, WorldState& worldState)
{
    if (!std::holds_alternative<Stop>(action)) {
        auto agent = worldState.ghosts[id];
        auto new_pos = move(agent.point, std::get<Direction>(action));

        if (worldState.layout.Walls().Get(new_pos.x, new_pos.y))
            return;

        worldState.ghosts[id].point = new_pos;

        if (worldState.ghosts[id].point == worldState.pacman.point) {
            if (agent.status == AgentStatus::NORMAL)
                worldState.gameState.lost = true;
            else
                ResetGhostPos(id, worldState);
        }
    }
}
