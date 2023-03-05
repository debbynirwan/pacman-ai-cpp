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
#include "gui_ghost.h"
#include <iostream>

namespace display {

GhostType& operator++(GhostType& type)
{
    switch (type) {
    case GhostType::RED:
        type = GhostType::ORANGE;
        break;
    case GhostType::ORANGE:
        type = GhostType::CYAN;
        break;
    case GhostType::CYAN:
        type = GhostType::PINK;
        break;
    case GhostType::PINK:
        type = GhostType::RED;
        break;
    }

    return type;
}

Ghost::Ghost(const Point& pos, const GhostType type, const int scale)
    : Agent(pos, scale)
    , m_normalAnimations()
    , m_lostAnimations()
{
    QString ghostType;

    if (type == GhostType::RED) {
        ghostType = "red";
    } else if (type == GhostType::ORANGE) {
        ghostType = "orange";
    } else if (type == GhostType::CYAN) {
        ghostType = "cyan";
    } else if (type == GhostType::PINK) {
        ghostType = "pink";
    }

    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/down1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/down2.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/left1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/left2.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/right1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/right2.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/up1.png"));
    m_normalAnimations.push_back(QPixmap(":/resources/ghost/" + ghostType + "/up2.png"));

    m_lostAnimations.push_back(QPixmap(":/resources/ghost/scared/down.png"));
    m_lostAnimations.push_back(QPixmap(":/resources/ghost/scared/left.png"));
    m_lostAnimations.push_back(QPixmap(":/resources/ghost/scared/right.png"));
    m_lostAnimations.push_back(QPixmap(":/resources/ghost/scared/up.png"));

    setPixmap(m_normalAnimations[0]);
}

void Ghost::Tick(const Point& pos, const Action& action, const bool scared)
{
    if (std::holds_alternative<Stop>(action))
        return;

    Direction dir = std::get<Direction>(action);

    m_currentPos.x = pos.x * m_scale;
    m_currentPos.y = pos.y * m_scale;

    switch (dir) {
    case Direction::SOUTH:
        if (scared)
            setPixmap(m_lostAnimations[0]);   // NOLINT
        else
            setPixmap(m_normalAnimations[0]);   // NOLINT
        break;
    case Direction::NORTH:
        if (scared)
            setPixmap(m_lostAnimations[3]);   // NOLINT
        else
            setPixmap(m_normalAnimations[6]);   // NOLINT
        break;
    case Direction::EAST:
        if (scared)
            setPixmap(m_lostAnimations[2]);   // NOLINT
        else
            setPixmap(m_normalAnimations[4]);   // NOLINT
        break;
    case Direction::WEST:
        if (scared)
            setPixmap(m_lostAnimations[1]);   // NOLINT
        else
            setPixmap(m_normalAnimations[2]);   // NOLINT
        break;
    }

    setPos(m_currentPos.x, m_currentPos.y);
}

}
