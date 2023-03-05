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

#include <QGraphicsPixmapItem>

#include "agent.h"
#include "point.h"

namespace display {

enum class GhostType { RED, ORANGE, CYAN, PINK };

class Agent : public QGraphicsPixmapItem {
public:
    Agent(const Point& pos, const int scale)
        : m_currentPos(pos)
        , m_scale(scale)
    {
        setPos(m_currentPos.x, m_currentPos.y);
    }

    virtual void Tick(const Point& pos, const Action& action, const bool scared) = 0;

protected:
    Point m_currentPos;
    int m_scale;
};

GhostType& operator++(GhostType& type);

}
