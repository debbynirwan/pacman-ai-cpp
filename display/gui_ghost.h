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

#include <QPixmap>
#include <vector>

#include "gui_agent.h"

namespace display {

class Ghost : public Agent {
public:
    Ghost(const Point& pos, const GhostType type, const int scale);
    virtual void Tick(const Point& pos, const Action& action, const bool scared) override;

private:
    std::vector<QPixmap> m_normalAnimations;
    std::vector<QPixmap> m_lostAnimations;
};

}
