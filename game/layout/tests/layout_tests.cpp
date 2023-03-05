#include "layout.h"
#include <gtest/gtest.h>
#include <stdexcept>

class LayoutTest : public ::testing::Test {
public:
    LayoutTest()
        : layout("sample.lay")
    {
    }

protected:
    Layout layout;
};

TEST_F(LayoutTest, Dimension)
{
    EXPECT_EQ(layout.Width(), 20);
    EXPECT_EQ(layout.Height(), 5);
}

TEST_F(LayoutTest, Walls)
{
    Grid<bool> walls = layout.Walls();

    EXPECT_EQ(walls.Get(0, 0), true);
    EXPECT_EQ(walls.Get(2, 1), false);
    EXPECT_EQ(walls.Get(19, 4), true);
    EXPECT_THROW(walls.Get(20, 5), std::out_of_range);
}

TEST_F(LayoutTest, Food)
{
    Grid<bool> food = layout.Food();

    EXPECT_EQ(food.Get(0, 0), false);
    EXPECT_EQ(food.Get(1, 1), true);
    EXPECT_EQ(food.Get(18, 3), true);
    EXPECT_THROW(food.Get(20, 5), std::out_of_range);
}

TEST_F(LayoutTest, Capsules)
{
    std::vector<Point> capsules = layout.Capsules();

    EXPECT_EQ(capsules.size(), 1);
    EXPECT_EQ(capsules[0], Point(16, 3));
}

TEST_F(LayoutTest, Agents)
{
    std::vector<Agent> agents = layout.Agents();

    EXPECT_EQ(agents.size(), 1);
    EXPECT_EQ(agents[0].id, 0);
    EXPECT_EQ(agents[0].type, AgentType::PACMAN);
    EXPECT_EQ(agents[0].status, AgentStatus::NORMAL);
    EXPECT_EQ(agents[0].point, Point(16, 1));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
