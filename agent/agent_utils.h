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

#include <optional>
#include <vector>

#include "agent.h"
#include "grid.h"

Direction reverse_direction(const Direction& dir);
std::optional<Direction> point_to_direction(const Point& point);
Point direction_to_point(const Direction& dir);
Point move(const Point& point, const Direction& dir);

std::vector<Direction> get_possible_actions(const Point& point, const Grid<bool>& walls);
std::vector<Point> get_illegal_neighbors(const Point& point, const Grid<bool>& walls);
