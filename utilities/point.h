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

#include <iostream>

struct Point {
    Point()
        : x(0)
        , y(0)
    {
    }

    Point(int _x, int _y)
        : x(_x)
        , y(_y)
    {
    }

    bool operator<(const Point& rhs) const;

    int x;
    int y;
};

Point operator+(const Point& point1, const Point& point2);
Point operator-(const Point& point1, const Point& point2);
bool operator==(const Point& point1, const Point& point2);
bool operator!=(const Point& point1, const Point& point2);

std::ostream& operator<<(std::ostream& os, const Point& point);
