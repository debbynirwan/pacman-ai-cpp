add_subdirectory(tests)

set(CMAKE_CXX_CLANG_TIDY clang-tidy;
    -checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;
    -warnings-as-errors=*;)

add_library(agent)

target_sources(agent
    PRIVATE agent_utils.cpp
            pacman_factory.cpp
            random_ghost_impl.cpp
            random_pacman_impl.cpp
)

target_include_directories(agent
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(agent 
    PRIVATE utilities
            game
            layout)
