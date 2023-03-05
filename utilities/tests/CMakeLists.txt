add_executable(grid_tests
               grid_tests.cpp)

target_link_libraries(grid_tests PRIVATE
                      gtest
                      utilities
                      Threads::Threads)

add_test(grid_tests grid_tests
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(point_tests
               point_tests.cpp)

target_link_libraries(point_tests PRIVATE
                      gtest
                      utilities
                      Threads::Threads)

add_test(point_tests point_tests
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_executable(agent_tests
               agent_tests.cpp)

target_link_libraries(agent_tests PRIVATE
                gtest
                utilities
                Threads::Threads)

add_test(agent_tests agent_tests
   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
