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
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "layout.h"

Layout::Layout(const std::string& layoutFile)
    : m_width(0)
    , m_height(0)
    , m_walls(0, 0, false)
    , m_food(0, 0, false)
    , m_capsules()
    , m_agents()
    , m_layoutFile(layoutFile)
{
    std::filesystem::path filePath(m_layoutFile);
    if (!std::filesystem::exists(filePath)) {
        throw std::filesystem::filesystem_error("invalid layout file: " + m_layoutFile,
                                                std::error_code());
    }

    ParseLayout(m_layoutFile);
}

void Layout::ParseLayout(const std::string& layoutFile)
{
    std::ifstream inputFile(m_layoutFile, std::ios::in);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inputFile, line))
        lines.push_back(line);

    m_height = lines.size();
    m_width = lines[0].size();
    m_walls = Grid<bool>(m_width, m_height, false);
    m_food = Grid<bool>(m_width, m_height, false);

    std::size_t agent_id = 1;
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            // process characters vertically
            ProcessChar(lines[y][x], x, y, agent_id);
        }
    }
}

void Layout::ProcessChar(const char ch, const int x, const int y, std::size_t& agent_id)
{
    switch (ch) {
    case '%':
        m_walls.Set(x, y, true);
        break;
    case '.':
        m_food.Set(x, y, true);
        break;
    case 'o':
        m_capsules.push_back({ x, y });
        break;
    case 'P':
        m_agents.push_back({
            0, AgentType::PACMAN, AgentStatus::NORMAL, {x, y}
        });
        break;
    case 'G':
        m_agents.push_back({
            agent_id, AgentType::GHOST, AgentStatus::NORMAL, {x, y}
        });
        agent_id++;
        break;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        m_agents.push_back({
            agent_id, AgentType::GHOST, AgentStatus::NORMAL, {x, y}
        });
        agent_id++;
        break;
    default:
        break;
    }
}

std::size_t Layout::Width() const { return m_width; }

std::size_t Layout::Height() const { return m_height; }

Grid<bool> Layout::Walls() const { return m_walls; }

Grid<bool> Layout::Food() const { return m_food; }

std::vector<Point> Layout::Capsules() const { return m_capsules; }

std::vector<Agent> Layout::Agents() const { return m_agents; }

std::ostream& operator<<(std::ostream& os, const Layout& layout)
{
    os << "width: " << layout.m_width << ";"
       << "height: " << layout.m_height;
    return os;
}
