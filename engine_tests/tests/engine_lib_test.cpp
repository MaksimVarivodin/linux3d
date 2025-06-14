//
// Created by maksymvarivodin on 8/2/24.
//

#include "point/point.hpp"
#include "gtest/gtest.h"

TEST(point_test, point_add)
{
    using namespace el;
    point<int, 2> p1(array<int, 2>({1, 2}));
    point<int, 2> p2(array<int, 2>({3, 4}));


    point<int, 2> p3(p1 + p2);
    EXPECT_EQ(p3.coordinate(0), 4);
    EXPECT_EQ(p3.coordinate(1), 6);
}
