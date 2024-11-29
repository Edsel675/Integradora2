#include <gtest/gtest.h>
#include "../include/NetworkOptimizer.h"

TEST(BasicTest, PointCreation) {
    Point p(100, 200);
    EXPECT_EQ(p.x, 100);
    EXPECT_EQ(p.y, 200);
}
