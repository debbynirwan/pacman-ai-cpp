add_subdirectory(tests)

set(CMAKE_CXX_CLANG_TIDY clang-tidy;
    -checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;
    -warnings-as-errors=*;)

add_library(utilities)

target_sources(utilities
    PRIVATE point.cpp
            agent.cpp
)

target_include_directories(utilities
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
