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

#include "agent.h"
#include "game_state.h"

class AgentImpl {
public:
    AgentImpl(const bool pacman)
        : m_pacman(pacman)
    {
    }

    virtual ~AgentImpl() { }

    virtual std::variant<Direction, Stop> GetAction(const WorldState& worldState,
                                                    const std::size_t id)
        = 0;

protected:
    bool IsPacman() const { return m_pacman; }

private:
    bool m_pacman;
};