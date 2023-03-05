add_executable(layout_tests
    layout_tests.cpp)

target_link_libraries(layout_tests 
    PRIVATE gtest
            layout
            utilities
            Threads::Threads)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sample.lay
               ${CMAKE_CURRENT_BINARY_DIR}/sample.lay)

add_test(layout_tests layout_tests
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
