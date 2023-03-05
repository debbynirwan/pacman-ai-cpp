#include "point.h"
#include <gtest/gtest.h>

TEST(PointTest, EqualityTest)
{
    Point p1(1, 1);
    Point p2(2, 1);
    Point p3(1, 1);

    EXPECT_EQ(p1, p3);
    EXPECT_NE(p1, p2);
}

TEST(PointTest, AdditionTest)
{
    Point p1(1, 1);
    Point p2(2, 1);
    Point p3(3, 2);

    EXPECT_EQ((p1 + p2), p3);
}

TEST(PointTest, SubtractionTest)
{
    Point p1(1, 1);
    Point p2(2, 1);
    Point p3(-1, 0);

    EXPECT_EQ((p1 - p2), p3);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
