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
#include "random_ghost_impl.h"
#include "agent_utils.h"
#include "random_selector.h"

RandomGhostImpl::RandomGhostImpl(const bool controlled)
    : AgentImpl(controlled)
{
}

std::variant<Direction, Stop> RandomGhostImpl::GetAction(const WorldState& worldState,
                                                         const std::size_t id)
{
    auto current_position = worldState.ghosts.at(id).point;
    auto walls = worldState.layout.Walls();

    auto valid_actions = get_possible_actions(current_position, walls);

    if (valid_actions.empty())
        return Stop {};
    else if (valid_actions.size() == 1)
        return valid_actions[0];

    Direction direction = *SelectRandomly(valid_actions.begin(), valid_actions.end());

    return direction;
}
