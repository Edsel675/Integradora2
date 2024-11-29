#ifndef NETWORK_OPTIMIZER_H
#define NETWORK_OPTIMIZER_H

#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

class Point {
public:
    double x, y;
    Point(double xCoord = 0.0, double yCoord = 0.0);
    double distanceTo(const Point& other) const;
    std::string toString() const;
};

class Edge {
public:
    int sourceNode;
    int destinationNode;
    int weight;
    Edge(int source, int destination, int edgeWeight);
    bool operator<(const Edge& other) const;
};

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    explicit DisjointSet(int size);
    int find(int x);
    void unite(int x, int y);
};

class NetworkOptimizer {
private:
    int numNodes;
    std::vector<std::vector<int>> distances;
    std::vector<std::vector<int>> capacities;
    std::vector<Point> centers;
    
    std::vector<std::vector<int>> readMatrix(const std::string& matrixName);
    bool bfs(std::vector<std::vector<int>>& residualGraph, int source, int sink, 
             std::vector<int>& parent);

public:
    NetworkOptimizer(int N);
    void readCenters();
    std::vector<Edge> calculateOptimalCabling();
    std::vector<int> calculateDeliveryRoute();
    int calculateMaxFlow();
    Point findNearestCenter(const Point& location);
};

#endif