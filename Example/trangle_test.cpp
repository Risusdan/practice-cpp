#include <gtest/gtest.h>
#include "trangle.h"

namespace
{
TEST(TriangleTest, InvalidInput)
{
    EXPECT_EQ(Invalid, GetTriangleType(-10, 20, 30));
    EXPECT_EQ(Invalid, GetTriangleType(10, -20, 30));
    EXPECT_EQ(Invalid, GetTriangleType(3, 4, -8));
}

TEST(TriangleTest, NonTriangle)
{
    EXPECT_EQ(Invalid, GetTriangleType(1, 1, 2));
    EXPECT_EQ(Invalid, GetTriangleType(10, 20, 30));
    EXPECT_EQ(Invalid, GetTriangleType(3, 4, 8));
}

TEST(TriangleTest, Equilateral)
{
    EXPECT_EQ(Equilateral, GetTriangleType(5, 5, 5));
    EXPECT_EQ(Equilateral, GetTriangleType(10, 10, 10));
    EXPECT_EQ(Equilateral, GetTriangleType(15, 15, 15));
}

TEST(TriangleTest, Isosceles)
{
    EXPECT_EQ(Isosceles, GetTriangleType(5, 5, 6));
    EXPECT_EQ(Isosceles, GetTriangleType(10, 10, 12));
    EXPECT_EQ(Isosceles, GetTriangleType(15, 15, 18));
}

TEST(TriangleTest, Scalene)
{
    EXPECT_EQ(Scalene, GetTriangleType(5, 6, 7));
    EXPECT_EQ(Scalene, GetTriangleType(10, 11, 12));
    EXPECT_EQ(Scalene, GetTriangleType(15, 16, 17));
}
} // namespace