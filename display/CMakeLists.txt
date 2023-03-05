set(CMAKE_CXX_CLANG_TIDY clang-tidy;
    -checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;
    -warnings-as-errors=*;)

add_library(display)

target_sources(display
    PRIVATE display.cpp
            gui.cpp
            gui_pacman.cpp
            gui_ghost.cpp
)

target_include_directories(display
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(display 
    PRIVATE layout
            utilities
            game
            Qt5::Widgets
            Qt5::Gui
            Qt5::Core)
