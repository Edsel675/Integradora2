#include <gtest/gtest.h>
#include "NetworkOptimizer.h"

TEST(NetworkOptimizerTest, CalculateOptimalCabling) {
    std::vector<std::vector<int>> distances = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };
    
    NetworkOptimizer optimizer(4);
    auto result = optimizer.calculateOptimalCabling();
    
    ASSERT_EQ(result.size(), 3);  // Un MST debe tener n-1 aristas
}

TEST(NetworkOptimizerTest, FindNearestCenter) {
    Point newLocation(400, 300);
    std::vector<Point> centers = {
        Point(200, 500),
        Point(300, 100),
        Point(450, 150)
    };
    
    Point nearest = findNearestCenter(newLocation, centers);
    ASSERT_NEAR(nearest.x, 450, 0.01);
    ASSERT_NEAR(nearest.y, 150, 0.01);
}

TEST(NetworkOptimizerTest, CalculateMaxFlow) {
    std::vector<std::vector<int>> capacities = {
        {0, 48, 12, 18},
        {52, 0, 42, 32},
        {18, 46, 0, 56},
        {24, 36, 52, 0}
    };
    
    NetworkOptimizer optimizer(4);
    int maxFlow = optimizer.calculateMaxFlow();
    ASSERT_GT(maxFlow, 0);
}