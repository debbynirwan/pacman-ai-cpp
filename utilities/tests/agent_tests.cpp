#include "agent.h"
#include <gtest/gtest.h>

TEST(AgentTest, EqualityTest)
{
    Agent agent1 { 1, AgentType::GHOST, AgentStatus::NORMAL, Point(0, 0) };

    Agent agent2 { 1, AgentType::GHOST, AgentStatus::NORMAL, Point(0, 0) };

    Agent agent3 { 1, AgentType::GHOST, AgentStatus::NORMAL, Point(0, 1) };

    Agent agent4 { 1, AgentType::GHOST, AgentStatus::SCARED, Point(0, 0) };

    Agent agent5 { 1, AgentType::PACMAN, AgentStatus::NORMAL, Point(0, 0) };

    Agent agent6 { 2, AgentType::GHOST, AgentStatus::NORMAL, Point(0, 0) };

    EXPECT_EQ(agent1, agent2);
    EXPECT_NE(agent1, agent3);
    EXPECT_NE(agent1, agent4);
    EXPECT_NE(agent1, agent5);
    EXPECT_NE(agent1, agent6);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
