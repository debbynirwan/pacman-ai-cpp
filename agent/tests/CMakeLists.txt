add_executable(agent_utils_tests
               agent_utils_tests.cpp)

target_link_libraries(agent_utils_tests PRIVATE
                      gtest
                      agent
                      utilities
                      Threads::Threads)

add_test(agent_utils_tests agent_utils_tests
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
