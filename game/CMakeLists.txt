add_subdirectory(layout)
add_subdirectory(tests)

set(CMAKE_CXX_CLANG_TIDY clang-tidy;
    -checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;
    -warnings-as-errors=*;)

add_library(game)

target_sources(game
    PRIVATE game_rules.cpp
            agent_rules.cpp
            game_state.cpp
)

target_include_directories(game
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(game 
    PRIVATE layout
            utilities
            agent
            yaml-cpp)
