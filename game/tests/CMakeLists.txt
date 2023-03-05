add_executable(agent_rules_tests
               agent_rules_tests.cpp)

add_executable(game_rules_tests
               game_rules_tests.cpp)


target_link_libraries(agent_rules_tests 
                PRIVATE gtest
                        layout
                        utilities
                        game
                        Threads::Threads)

target_link_libraries(game_rules_tests 
                PRIVATE gtest
                        layout
                        utilities
                        game
                        Threads::Threads)


add_test(agent_rules_tests agent_rules_tests
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(game_rules_tests game_rules_tests
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/game_rules.lay
               ${CMAKE_CURRENT_BINARY_DIR}/game_rules.lay)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/agent_rules.lay
               ${CMAKE_CURRENT_BINARY_DIR}/agent_rules.lay)