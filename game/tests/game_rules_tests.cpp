#include "game_rules.h"
#include <gtest/gtest.h>
#include <stdexcept>

class GameRulesTest : public ::testing::Test {
public:
    GameRulesTest()
        : gameRules("game_rules.lay", "../../configs/configs.yaml")
    {
    }   // 20 x 5

protected:
    GameRules gameRules;
};

TEST_F(GameRulesTest, ScaredTimer)
{
    std::map<std::size_t, Action> actions;

    auto state_before = gameRules.GetCurrentWorldState();
    EXPECT_EQ(state_before.scaredTimer, 0);

    for (const auto& [id, ghost] : state_before.ghosts) {
        EXPECT_EQ(ghost.status, AgentStatus::NORMAL);
    }

    actions.insert({ 0, Direction::SOUTH });
    gameRules.Tick(actions);
    gameRules.Tick(actions);
    auto state_after = gameRules.GetCurrentWorldState();

    EXPECT_TRUE(state_after.scaredTimer > 0);

    for (const auto& [id, ghost] : state_after.ghosts) {
        EXPECT_EQ(ghost.status, AgentStatus::SCARED);
    }

    gameRules.Tick(actions);

    EXPECT_EQ(gameRules.GetCurrentWorldState().scaredTimer, state_after.scaredTimer - 1);
}

TEST_F(GameRulesTest, PacmanWon)
{
    std::map<std::size_t, Action> actions;

    auto state_before = gameRules.GetCurrentWorldState();
    EXPECT_FALSE(state_before.gameState.won.has_value());

    actions.insert({ 0, Direction::WEST });
    gameRules.Tick(actions);
    auto state_after = gameRules.GetCurrentWorldState();

    EXPECT_TRUE(state_after.gameState.won.value());
}

TEST_F(GameRulesTest, DecrementScore)
{
    std::map<std::size_t, Action> actions;

    auto state_before = gameRules.GetCurrentWorldState();
    EXPECT_EQ(state_before.gameState.score, 0);

    actions.insert({ 0, Direction::EAST });
    gameRules.Tick(actions);
    auto state_after = gameRules.GetCurrentWorldState();

    EXPECT_TRUE(state_after.gameState.score < 0);
}

TEST_F(GameRulesTest, IncrementScore)
{
    std::map<std::size_t, Action> actions;

    auto state_before = gameRules.GetCurrentWorldState();
    EXPECT_EQ(state_before.gameState.score, 0);

    actions.insert({ 0, Direction::WEST });
    gameRules.Tick(actions);
    auto state_after = gameRules.GetCurrentWorldState();

    EXPECT_TRUE(state_after.gameState.score > 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
