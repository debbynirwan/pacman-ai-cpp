#include "agent_utils.h"
#include <algorithm>
#include <gtest/gtest.h>

TEST(AgentUtilsTests, ReverseDirection)
{
    EXPECT_EQ(reverse_direction(Direction::SOUTH), Direction::NORTH);
    EXPECT_EQ(reverse_direction(Direction::NORTH), Direction::SOUTH);
    EXPECT_EQ(reverse_direction(Direction::EAST), Direction::WEST);
    EXPECT_EQ(reverse_direction(Direction::WEST), Direction::EAST);
}

TEST(AgentUtilsTests, PointToDirection)
{
    EXPECT_EQ(point_to_direction(Point(0, 1)), Direction::SOUTH);
    EXPECT_EQ(point_to_direction(Point(0, -1)), Direction::NORTH);
    EXPECT_EQ(point_to_direction(Point(1, 0)), Direction::EAST);
    EXPECT_EQ(point_to_direction(Point(-1, 0)), Direction::WEST);

    EXPECT_EQ(point_to_direction(Point(1, 1)), std::nullopt);
    EXPECT_EQ(point_to_direction(Point(-1, -1)), std::nullopt);
    EXPECT_EQ(point_to_direction(Point(0, 0)), std::nullopt);
    EXPECT_EQ(point_to_direction(Point(1, -1)), std::nullopt);
    EXPECT_EQ(point_to_direction(Point(-1, 1)), std::nullopt);
}

TEST(AgentUtilsTests, DirectionToPoint)
{
    EXPECT_EQ(direction_to_point(Direction::SOUTH), Point(0, 1));
    EXPECT_EQ(direction_to_point(Direction::NORTH), Point(0, -1));
    EXPECT_EQ(direction_to_point(Direction::EAST), Point(1, 0));
    EXPECT_EQ(direction_to_point(Direction::WEST), Point(-1, 0));
}

TEST(AgentUtilsTests, Move)
{
    EXPECT_EQ(move(Point(0, 0), Direction::SOUTH), Point(0, 1));
    EXPECT_EQ(move(Point(0, 0), Direction::NORTH), Point(0, -1));
    EXPECT_EQ(move(Point(0, 0), Direction::EAST), Point(1, 0));
    EXPECT_EQ(move(Point(0, 0), Direction::WEST), Point(-1, 0));
}

TEST(AgentUtilsTests, PossibleActions)
{
    Grid<bool> walls(3, 3, false);
    walls.Set(0, 1, true);

    auto poss = get_possible_actions(Point(1, 1), walls);

    EXPECT_TRUE(poss.size() > 0);

    auto north_itr = std::find(poss.begin(), poss.end(), Direction::NORTH);
    auto south_itr = std::find(poss.begin(), poss.end(), Direction::SOUTH);
    auto east_itr = std::find(poss.begin(), poss.end(), Direction::EAST);
    auto west_itr = std::find(poss.begin(), poss.end(), Direction::WEST);

    EXPECT_TRUE(north_itr != poss.end());
    EXPECT_TRUE(south_itr != poss.end());
    EXPECT_TRUE(east_itr != poss.end());
    EXPECT_TRUE(west_itr == poss.end());
}

TEST(AgentUtilsTests, IllegalNeighbors)
{
    Grid<bool> walls(3, 3, false);
    walls.Set(0, 1, true);

    auto illegal = get_illegal_neighbors(Point(1, 1), walls);

    EXPECT_TRUE(illegal.size() == 1);
    EXPECT_EQ(illegal[0], Point(0, 1));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
