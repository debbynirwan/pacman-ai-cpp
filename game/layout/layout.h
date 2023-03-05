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
#include "grid.h"
#include "point.h"
#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

class Layout {
public:
    Layout(const std::string& layoutFile);

    Layout(const Layout& otherLayout) = default;
    Layout(Layout&& otherLayout) = default;
    Layout& operator=(const Layout& otherLayout) = default;
    Layout& operator=(Layout&& otherLayout) = default;

    std::size_t Width() const;
    std::size_t Height() const;
    Grid<bool> Walls() const;
    Grid<bool> Food() const;
    std::vector<Point> Capsules() const;
    std::vector<Agent> Agents() const;

private:
    friend std::ostream& operator<<(std::ostream& os, const Layout& layout);

    void ParseLayout(const std::string& layoutFile);
    void ProcessChar(const char ch, const int x, const int y, std::size_t& agent_id);

    std::size_t m_width;
    std::size_t m_height;
    Grid<bool> m_walls;
    Grid<bool> m_food;
    std::vector<Point> m_capsules;
    std::vector<Agent> m_agents;
    std::string m_layoutFile;
};

std::ostream& operator<<(std::ostream& os, const Layout& layout);
