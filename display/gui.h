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

#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <map>

#include "display.h"
#include "gui_ghost.h"
#include "gui_pacman.h"

namespace display {

class GuiDisplay : public DisplayInterface {
public:
    GuiDisplay(const DisplayType type, const Layout& layout);
    virtual void Initialize(const WorldState& worldState) override;
    virtual void Tick(const WorldState& worldState,
                      const std::map<std::size_t, Action>& actions) override;

private:
    QGraphicsView m_view;
    QGraphicsScene* m_scene;
    display::Pacman* m_pacman;
    std::map<std::size_t, display::Ghost*> m_ghosts;
    std::map<Point, QGraphicsEllipseItem*> m_food;
    std::map<Point, QGraphicsEllipseItem*> m_capsules;
    QGraphicsTextItem *m_score, *m_status;
    static constexpr int SCALE = 15;
    static constexpr int DISPLAY_WIDTH = 27;
    static constexpr int DISPLAY_HEIGHT = 2;
    static constexpr int SCORE_TEXT_POS = 0;
    static constexpr int STATUS_TEXT_POS = 13;
    static constexpr int HEIGHT_BUFFER = 2;
    static constexpr const char* GAME_TITLE = "Pac-man AI cpp";
};

}
