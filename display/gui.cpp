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
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QIcon>
#include <QPixmap>

#include <algorithm>
#include <iostream>

#include "gui.h"

namespace display {

GuiDisplay::GuiDisplay(const DisplayType type, const Layout& layout)
    : DisplayInterface(type)
    , m_view()
    , m_scene(new QGraphicsScene())
    , m_pacman(nullptr)
    , m_ghosts()
    , m_food()
    , m_capsules()
    , m_score(nullptr)
    , m_status(nullptr)
{
    int display_height = DISPLAY_HEIGHT * SCALE;
    int display_width = DISPLAY_WIDTH * SCALE;

    int window_width = static_cast<int>(layout.Width()) * SCALE;
    int window_height = static_cast<int>(layout.Height()) * SCALE + display_height;

    if (window_width < display_width)
        window_width = display_width;

    m_view.setWindowTitle(GAME_TITLE);
    m_view.setWindowIcon(QIcon(QPixmap(":/resources/pacman_logo.png")));
    m_view.resize(window_width, window_height);
    m_view.setScene(m_scene);
    m_view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view.setBackgroundBrush(Qt::black);

    for (int x = 0; x < layout.Width(); x++) {
        for (int y = 0; y < layout.Height(); y++) {
            if (layout.Walls().Get(x, y)) {
                QGraphicsRectItem* wall = new QGraphicsRectItem();   // NOLINT
                wall->setRect(x * SCALE, y * SCALE, SCALE, SCALE);
                wall->setBrush(Qt::blue);
                m_scene->addItem(wall);
            }

            if (layout.Food().Get(x, y)) {
                int pos_x = x * SCALE + SCALE / 2 - 3;
                int pos_y = y * SCALE + SCALE / 2 - 3;
                QGraphicsEllipseItem* food = new QGraphicsEllipseItem(pos_x, pos_y, 6, 6);  // NOLINT
                food->setBrush(Qt::white);
                m_scene->addItem(food);
                m_food.insert({
                    Point {x, y},
                     food
                });
            }
        }
    }

    for (const auto& capsule : layout.Capsules()) {
        int pos_x = capsule.x * SCALE + SCALE / 2 - 3;
        int pos_y = capsule.y * SCALE + SCALE / 2 - 3;
        QGraphicsEllipseItem* cap = new QGraphicsEllipseItem(pos_x, pos_y, 8, 6);   // NOLINT
        cap->setBrush(Qt::yellow);
        m_scene->addItem(cap);
        m_capsules.insert({
            Point {capsule.x, capsule.y},
             cap
        });
    }

    m_score = new QGraphicsTextItem("Score: 0");   // NOLINT
    m_score->setPos(SCORE_TEXT_POS, window_height - HEIGHT_BUFFER * SCALE);
    m_score->setDefaultTextColor(Qt::yellow);
    m_scene->addItem(m_score);

    m_status = new QGraphicsTextItem("Status: Running");   // NOLINT
    m_status->setPos(STATUS_TEXT_POS * SCALE, window_height - HEIGHT_BUFFER * SCALE);
    m_status->setDefaultTextColor(Qt::yellow);
    m_scene->addItem(m_status);

    m_view.show();
}

void GuiDisplay::Initialize(const WorldState& worldState)
{
    GhostType ghostType = GhostType::RED;

    m_pacman = new display::Pacman(   // NOLINT
        { worldState.pacman.point.x * SCALE, worldState.pacman.point.y * SCALE }, SCALE);
    m_scene->addItem(m_pacman);

    for (const auto& [id, agent] : worldState.ghosts) {
        int pos_x = agent.point.x * SCALE;
        int pos_y = agent.point.y * SCALE;

        display::Ghost* ghost = new display::Ghost({ pos_x, pos_y }, ghostType, SCALE);
        m_scene->addItem(ghost);
        m_ghosts.insert({ id, ghost });

        ++ghostType;
    }
}

void GuiDisplay::Tick(const WorldState& worldState, const std::map<std::size_t, Action>& actions)
{
    for (const auto& [id, agent] : worldState.ghosts) {
        m_ghosts[id]->Tick(agent.point, actions.at(id), (agent.status == AgentStatus::SCARED));
    }

    m_pacman->Tick(worldState.pacman.point, actions.at(0), false);

    QString score = "Score: " + QString::number(worldState.gameState.score);
    m_score->setPlainText(score);

    for (auto itr = m_food.begin(); itr != m_food.end();) {
        if (!worldState.food.Get(itr->first.x, itr->first.y)) {
            m_scene->removeItem(itr->second);
            itr = m_food.erase(itr);
        } else {
            ++itr;
        }
    }

    for (auto itr = m_capsules.begin(); itr != m_capsules.end();) {
        auto capsule_itr
            = std::find(worldState.capsules.begin(), worldState.capsules.end(), itr->first);

        if (capsule_itr == worldState.capsules.end()) {
            m_scene->removeItem(itr->second);
            itr = m_capsules.erase(itr);
        } else {
            ++itr;
        }
    }

    if (worldState.gameState.lost.has_value() && worldState.gameState.lost.value()) {
        m_status->setPlainText("Status: Lost");
    } else if (worldState.gameState.won.has_value() && worldState.gameState.won.value()) {
        m_status->setPlainText("Status: Won");
    }
}

}
