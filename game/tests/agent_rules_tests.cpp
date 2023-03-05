#include "agent_rules.h"
#include <algorithm>
#include <gtest/gtest.h>
#include <stdexcept>

class AgentRulesTest : public ::testing::Test {
public:
    AgentRulesTest()
        : pacmanRules("../../configs/configs.yaml")
        , ghostRules("../../configs/configs.yaml")
        , worldState("agent_rules.lay")
    {
    }   // 20 x 5

protected:
    PacmanRules pacmanRules;
    GhostRules ghostRules;
    const WorldState worldState;
};

TEST_F(AgentRulesTest, PacmanPoseUnchangedAfterStopAction)
{
    auto currentPos = worldState.pacman.point;   // (16, 1)
    auto state = worldState;
    pacmanRules.Tick(0, Stop {}, state);

    EXPECT_EQ(state.pacman.point, currentPos);
}

TEST_F(AgentRulesTest, PacmanPoseUnchangedAfterInvalidAction)
{
    auto currentPos = worldState.pacman.point;   // (16, 1)
    auto state = worldState;
    pacmanRules.Tick(0, Direction::NORTH, state);

    EXPECT_EQ(state.pacman.point, currentPos);
}

TEST_F(AgentRulesTest, PacmanPoseChangedAfterValidAction)
{
    auto currentPos = worldState.pacman.point;   // (16, 1)
    auto state = worldState;
    pacmanRules.Tick(0, Direction::SOUTH, state);

    EXPECT_EQ(state.pacman.point, Point(16, 2));
}

TEST_F(AgentRulesTest, FoodEatenByPacman)
{
    auto state = worldState;

    EXPECT_TRUE(state.food.Get(15, 1));
    pacmanRules.Tick(0, Direction::WEST, state);
    EXPECT_FALSE(state.food.Get(15, 1));
}

TEST_F(AgentRulesTest, CapsuleEatenByPacman)
{
    auto state = worldState;
    Point capsulePos = Point(16, 3);
    auto itr_before = std::find(state.capsules.begin(), state.capsules.end(), capsulePos);

    EXPECT_TRUE(itr_before != state.capsules.end());

    for (const auto& [id, ghost] : state.ghosts) {
        EXPECT_EQ(ghost.status, AgentStatus::NORMAL);
    }

    pacmanRules.Tick(0, Direction::SOUTH, state);
    ghostRules.Tick(1, Direction::EAST, state);
    pacmanRules.Tick(0, Direction::SOUTH, state);
    ghostRules.Tick(1, Direction::EAST, state);

    auto itr_after = std::find(state.capsules.begin(), state.capsules.end(), capsulePos);

    EXPECT_TRUE(itr_after == state.capsules.end());

    for (const auto& [id, ghost] : state.ghosts) {
        EXPECT_EQ(ghost.status, AgentStatus::SCARED);
    }

    EXPECT_TRUE(state.scaredTimer > 0);
}

TEST_F(AgentRulesTest, PacmanMeetsGhost)
{
    auto state = worldState;

    state.ghosts[0].point = Point(15, 1);
    pacmanRules.Tick(0, Direction::WEST, state);

    EXPECT_TRUE(state.gameState.lost.value());
}

// Ghost Rules' Test Cases
TEST_F(AgentRulesTest, GhostPoseUnchangedAfterStopAction)
{
    auto currentPos = worldState.ghosts.at(1).point;
    auto state = worldState;
    ghostRules.Tick(1, Stop {}, state);

    EXPECT_EQ(state.ghosts[1].point, currentPos);
}

TEST_F(AgentRulesTest, GhostPoseUnchangedAfterInvalidAction)
{
    auto currentPos = worldState.ghosts.at(1).point;
    auto state = worldState;
    ghostRules.Tick(1, Direction::NORTH, state);

    EXPECT_EQ(state.ghosts[1].point, currentPos);
}

TEST_F(AgentRulesTest, GhostPoseChangedAfterValidAction)
{
    auto currentPos = worldState.ghosts.at(1).point;
    auto state = worldState;
    ghostRules.Tick(1, Direction::WEST, state);

    EXPECT_EQ(state.ghosts[1].point, Point(1, 1));
}

TEST_F(AgentRulesTest, FoodNotEatenByGhost)
{
    auto state = worldState;

    EXPECT_TRUE(state.food.Get(1, 1));
    ghostRules.Tick(1, Direction::WEST, state);
    EXPECT_TRUE(state.food.Get(1, 1));
}

TEST_F(AgentRulesTest, CapsuleNotEatenByGhost)
{
    auto state = worldState;
    Point capsulePos = Point(3, 1);
    auto itr_before = std::find(state.capsules.begin(), state.capsules.end(), capsulePos);

    EXPECT_TRUE(itr_before != state.capsules.end());

    ghostRules.Tick(1, Direction::EAST, state);

    auto itr_after = std::find(state.capsules.begin(), state.capsules.end(), capsulePos);

    EXPECT_TRUE(itr_after != state.capsules.end());
    EXPECT_TRUE(state.scaredTimer == 0);
}

TEST_F(AgentRulesTest, GhostPosReset)
{
    auto state = worldState;
    auto ghost_init_pos = state.ghosts[1].point;

    state.ghosts[1].status = AgentStatus::SCARED;
    state.pacman.point = Point(1, 1);

    ghostRules.Tick(1, Direction::WEST, state);

    EXPECT_EQ(state.ghosts[1].point, ghost_init_pos);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
