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
#include "agent.h"

bool operator==(const Agent& agent1, const Agent& agent2)
{
    return ((agent1.id == agent2.id) && (agent1.point == agent2.point)
            && (agent1.status == agent2.status) && (agent1.type == agent2.type));
}

bool operator!=(const Agent& agent1, const Agent& agent2) { return !(operator==(agent1, agent2)); }

std::ostream& operator<<(std::ostream& os, const AgentType& agentType)
{
    if (agentType == AgentType::PACMAN) {
        os << "PACMAN";
    } else {
        os << "GHOST";
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const AgentStatus& agentStatus)
{
    if (agentStatus == AgentStatus::NORMAL) {
        os << "NORMAL";
    } else {
        os << "SCARED";
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Direction& direction)
{
    if (direction == Direction::NORTH) {
        os << "NORTH";
    } else if (direction == Direction::SOUTH) {
        os << "SOUTH";
    } else if (direction == Direction::EAST) {
        os << "EAST";
    } else if (direction == Direction::WEST) {
        os << "WEST";
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Action& action)
{
    if (std::holds_alternative<Stop>(action)) {
        os << "Stop";
    } else {
        os << std::get<Direction>(action);
    }

    return os;
}
