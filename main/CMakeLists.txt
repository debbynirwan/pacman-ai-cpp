add_executable(pacman)

target_sources(pacman
    PRIVATE main.cpp
            imgresources.qrc
)

target_include_directories(pacman
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(pacman 
    PRIVATE sim_manager
            utilities
            display
            game
            layout
            agent
            Qt5::Widgets
            Qt5::Core)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../layout_files/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../layout_files)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../configs/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../configs)
