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
#include "gui_pacman.h"
#include <iostream>

namespace display {

Pacman::Pacman(const Point& pos, const int scale)
    : Agent(pos, scale)
    , m_normalAnimations()
    , m_prevDir()
{
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/start.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/down1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/down2.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/up1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/up2.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/left1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/left2.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/right1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/pacman/right2.png"));

    setPixmap(m_normalAnimations[0]);
}

void Pacman::Tick(const Point& pos, const Action& action, const bool scared)
{
    if ((m_currentPos.x == pos.x * m_scale) && (m_currentPos.y == pos.y * m_scale)) {
        switch (m_prevDir) {
        case Direction::SOUTH:
            setPixmap(m_normalAnimations[1]);   // NOLINT
            break;
        case Direction::NORTH:
            setPixmap(m_normalAnimations[3]);   // NOLINT
            break;
        case Direction::EAST:
            setPixmap(m_normalAnimations[7]);   // NOLINT
            break;
        case Direction::WEST:
            setPixmap(m_normalAnimations[5]);   // NOLINT
            break;
        }
        return;
    }

    if (std::holds_alternative<Stop>(action))
        return;

    Direction dir = std::get<Direction>(action);

    m_currentPos.x = pos.x * m_scale;
    m_currentPos.y = pos.y * m_scale;

    switch (dir) {
    case Direction::SOUTH:
        setPixmap(m_normalAnimations[2]);   // NOLINT
        break;
    case Direction::NORTH:
        setPixmap(m_normalAnimations[4]);   // NOLINT
        break;
    case Direction::EAST:
        setPixmap(m_normalAnimations[8]);   // NOLINT
        break;
    case Direction::WEST:
        setPixmap(m_normalAnimations[6]);   // NOLINT
        break;
    }

    m_prevDir = dir;
    setPos(m_currentPos.x, m_currentPos.y);
}

}
