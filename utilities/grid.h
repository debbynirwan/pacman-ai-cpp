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

#include <cstdint>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

template <typename T> class Grid {
public:
    Grid(const std::size_t width, const std::size_t height, const T& initial_value)
        : m_width(width)
        , m_height(height)
        , m_data((m_width * m_height), initial_value)
        , m_nonInitialValueCache()
        , m_initialValue(initial_value)
    {
    }

    Grid(const Grid& otherGrid) = default;
    Grid(Grid&& otherGrid) = default;
    Grid& operator=(const Grid& otherGrid) = default;
    Grid& operator=(Grid&& otherGrid) = default;

    T At(const std::size_t index);
    std::size_t Size() const;
    void Set(const std::size_t x, const std::size_t y, const T& val);
    T Get(const std::size_t x, const std::size_t y) const;
    bool AllInitialValues() const;

private:
    friend std::ostream& operator<<(std::ostream& os, const Grid& grid)
    {
        os << "width: " << grid.m_width << ";"
           << "height: " << grid.m_height;
        return os;
    }

    std::size_t m_width;
    std::size_t m_height;
    std::vector<T> m_data;
    std::set<std::size_t> m_nonInitialValueCache;
    T m_initialValue;
};

template <typename T> T Grid<T>::At(const std::size_t index) { return m_data[index]; }

template <typename T> std::size_t Grid<T>::Size() const { return m_data.size(); }

template <typename T> void Grid<T>::Set(const std::size_t x, const std::size_t y, const T& val)
{
    if (x >= m_width || y >= m_height)
        throw std::out_of_range("set");
    std::size_t index = y * m_width + x;
    m_data[index] = val;

    if (val != m_initialValue)
        m_nonInitialValueCache.insert(index);
    else
        m_nonInitialValueCache.erase(index);
}

template <typename T> T Grid<T>::Get(const std::size_t x, const std::size_t y) const
{
    if (x >= m_width || y >= m_height)
        throw std::out_of_range("get");
    std::size_t index = y * m_width + x;
    return m_data[index];
}

template <typename T> bool Grid<T>::AllInitialValues() const
{
    return (m_nonInitialValueCache.empty());
}
