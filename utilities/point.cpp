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
#include "point.h"

bool Point::operator<(const Point& rhs) const
{
    if (x < rhs.x || y < rhs.y)
        return true;
    else
        return false;
}

Point operator+(const Point& point1, const Point& point2)
{
    return { point1.x + point2.x, point1.y + point2.y };
}

Point operator-(const Point& point1, const Point& point2)
{
    return { point1.x - point2.x, point1.y - point2.y };
}

bool operator==(const Point& point1, const Point& point2)
{
    return ((point1.x == point2.x) && (point1.y == point2.y));
}

bool operator!=(const Point& point1, const Point& point2) { return !(operator==(point1, point2)); }

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "{" << point.x << ", " << point.y << "}";

    return os;
}
