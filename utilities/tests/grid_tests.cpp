#include "grid.h"
#include <gtest/gtest.h>
#include <stdexcept>

class GridTest : public ::testing::Test {
public:
    GridTest()
        : grid(4, 3, 0)
    {
    }

protected:
    Grid<int> grid;
};

TEST_F(GridTest, Size) { EXPECT_EQ(grid.Size(), 12); }

TEST_F(GridTest, SetGetIndex)
{
    grid.Set(1, 1, 200);

    EXPECT_EQ(grid.Get(1, 1), 200);
}

TEST_F(GridTest, OutOfRange)
{
    EXPECT_THROW(grid.Get(4, 4), std::out_of_range);
    EXPECT_THROW(grid.Set(5, 5, 0), std::out_of_range);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
