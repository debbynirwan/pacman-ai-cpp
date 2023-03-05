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

#include "agent_utils.h"

Direction reverse_direction(const Direction& dir)
{
    if (dir == Direction::NORTH)
        return Direction::SOUTH;
    else if (dir == Direction::SOUTH)
        return Direction::NORTH;
    else if (dir == Direction::EAST)
        return Direction::WEST;
    else if (dir == Direction::WEST)
        return Direction::EAST;
    else
        return dir;
}

std::optional<Direction> point_to_direction(const Point& point)
{
    if (point.x == 0 && point.y > 0)
        return Direction::SOUTH;
    else if (point.x == 0 && point.y < 0)
        return Direction::NORTH;
    else if (point.x > 0 && point.y == 0)
        return Direction::EAST;
    else if (point.x < 0 && point.y == 0)
        return Direction::WEST;
    else
        return std::nullopt;
}

Point direction_to_point(const Direction& dir)
{
    if (dir == Direction::NORTH)
        return { 0, -1 };
    else if (dir == Direction::SOUTH)
        return { 0, 1 };
    else if (dir == Direction::EAST)
        return { 1, 0 };
    else if (dir == Direction::WEST)
        return { -1, 0 };
    else
        return { 0, 0 };
}

Point move(const Point& point, const Direction& dir)
{
    if (dir == Direction::NORTH)
        return point + Point { 0, -1 };
    else if (dir == Direction::SOUTH)
        return point + Point { 0, 1 };
    else if (dir == Direction::EAST)
        return point + Point { 1, 0 };
    else if (dir == Direction::WEST)
        return point + Point { -1, 0 };
    else
        return point;
}

std::vector<Direction> get_possible_actions(const Point& point, const Grid<bool>& walls)
{
    std::vector<Direction> possible_actions;

    Point south = move(point, Direction::SOUTH);
    Point north = move(point, Direction::NORTH);
    Point east = move(point, Direction::EAST);
    Point west = move(point, Direction::WEST);

    if (!walls.Get(static_cast<std::size_t>(south.x), static_cast<std::size_t>(south.y))) {
        possible_actions.push_back(Direction::SOUTH);
    }

    if (!walls.Get(static_cast<std::size_t>(north.x), static_cast<std::size_t>(north.y))) {
        possible_actions.push_back(Direction::NORTH);
    }

    if (!walls.Get(static_cast<std::size_t>(east.x), static_cast<std::size_t>(east.y))) {
        possible_actions.push_back(Direction::EAST);
    }

    if (!walls.Get(static_cast<std::size_t>(west.x), static_cast<std::size_t>(west.y))) {
        possible_actions.push_back(Direction::WEST);
    }

    return possible_actions;
}

std::vector<Point> get_illegal_neighbors(const Point& point, const Grid<bool>& walls)
{
    std::vector<Point> illegal_neigbors;

    Point south = move(point, Direction::SOUTH);
    Point north = move(point, Direction::NORTH);
    Point east = move(point, Direction::EAST);
    Point west = move(point, Direction::WEST);

    if (walls.Get(static_cast<std::size_t>(south.x), static_cast<std::size_t>(south.y))) {
        illegal_neigbors.push_back(south);
    }

    if (walls.Get(static_cast<std::size_t>(north.x), static_cast<std::size_t>(north.y))) {
        illegal_neigbors.push_back(north);
    }

    if (walls.Get(static_cast<std::size_t>(east.x), static_cast<std::size_t>(east.y))) {
        illegal_neigbors.push_back(east);
    }

    if (walls.Get(static_cast<std::size_t>(west.x), static_cast<std::size_t>(west.y))) {
        illegal_neigbors.push_back(west);
    }

    return illegal_neigbors;
}
