set(CMAKE_CXX_CLANG_TIDY clang-tidy;
    -checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;
    -warnings-as-errors=*;)

add_library(sim_manager)

target_sources(sim_manager
    PRIVATE sim_manager.cpp
)

target_include_directories(sim_manager
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(sim_manager 
    PRIVATE utilities
            display
            game
            layout
            agent
            Qt5::Widgets
            Qt5::Core
            yaml-cpp)
