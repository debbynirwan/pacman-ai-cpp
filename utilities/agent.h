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

#include "point.h"
#include <ostream>
#include <variant>

enum class AgentType { PACMAN, GHOST };

enum class AgentStatus { NORMAL, SCARED };

struct Agent {
    std::size_t id;
    AgentType type;
    AgentStatus status;
    Point point;
};

enum class Direction { NORTH, SOUTH, EAST, WEST };

struct Stop { };

using Action = std::variant<Direction, Stop>;

bool operator==(const Agent& agent1, const Agent& agent2);
bool operator!=(const Agent& agent1, const Agent& agent2);

std::ostream& operator<<(std::ostream& os, const AgentType& agentType);
std::ostream& operator<<(std::ostream& os, const AgentStatus& agentStatus);
std::ostream& operator<<(std::ostream& os, const Direction& direction);
std::ostream& operator<<(std::ostream& os, const Action& action);
