add_subdirectory(tests)

set(CMAKE_CXX_CLANG_TIDY clang-tidy;
    -checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;
    -warnings-as-errors=*;)

add_library(layout)

target_sources(layout
    PRIVATE layout.cpp
)

target_include_directories(layout
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(layout 
    PRIVATE utilities)
