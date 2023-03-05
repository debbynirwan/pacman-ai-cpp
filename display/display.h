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
#include "layout.h"
#include <memory>
#include <string>

namespace display {

enum class DisplayType { GUI, CONSOLE };

class DisplayInterface {
public:
    DisplayInterface(const DisplayType type)
        : m_type(type)
    {
    }

    DisplayType GetType() const { return m_type; }

    std::string GetName() const
    {
        if (m_type == DisplayType::CONSOLE)
            return "CONSOLE";
        else
            return "GUI";
    }

    virtual void Tick(const WorldState& worldState, const std::map<std::size_t, Action>& actions)
        = 0;
    virtual void Initialize(const WorldState& worldState) = 0;

private:
    DisplayType m_type;
};

std::shared_ptr<DisplayInterface> MakeDisplay(const DisplayType type, const Layout& layout);

}
