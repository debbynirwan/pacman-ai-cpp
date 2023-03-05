cmake_minimum_required(VERSION 3.16.0)
project(pacman-ai-cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Widgets Gui Core REQUIRED)

enable_testing()

add_subdirectory(game)
add_subdirectory(utilities)
add_subdirectory(agent)
add_subdirectory(sim_manager)
add_subdirectory(display)
add_subdirectory(main)
