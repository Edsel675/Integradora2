/*
 * Análisis y diseño de algoritmos avanzados (Gpo 604)
 * 
 * Proyecto: Optimizador de Red de Internet
 * 
 * Elaborado por:
 * - Edsel De Jesus Cisneros Bautista - A00838063
 * - Abdiel Fritsche Barajas - A01234933
 * - Miguel Mendoza Jaidar - A01234354
 * - Daniel Rubies Isla - A00832425
 * 
 * Fecha: Noviembre 2024
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

namespace Config {
    const int MIN_NODES = 1;
    const int MAX_NODES = 1000;
    const double MAX_DISTANCE = 1000000.0;
    const double EPSILON = 1e-10;
}

class Logger {
public:
    static void logError(const string& message) {
        cerr << "[ERROR] " << message << endl;
    }

    static void logInfo(const string& message) {
        cout << "[INFO] " << message << endl;
    }

    static void logWarning(const string& message) {
        cout << "[WARNING] " << message << endl;
    }
};

// Estructura para representar un punto en el plano
class Point {
public:
    double x, y;

    Point(double xCoord = 0.0, double yCoord = 0.0) {
        if (!isfinite(xCoord) || !isfinite(yCoord)) {
            throw invalid_argument("Coordenadas inválidas");
        }
        x = xCoord;
        y = yCoord;
    }

    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    string toString() const {
        ostringstream oss;
        oss << fixed << setprecision(2) << "(" << x << ", " << y << ")";
        return oss.str();
    }
};

// Estructura para representar una arista en el grafo
class Edge {
public:
    int sourceNode;
    int destinationNode;
    int weight;

    Edge(int source, int destination, int edgeWeight) 
        : sourceNode(source), destinationNode(destination), weight(edgeWeight) {
        if (edgeWeight < 0) {
            throw invalid_argument("Peso de arista negativo");
        }
    }

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Clase DisjointSet para el algoritmo de Kruskal
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    explicit DisjointSet(int size) {
        if (size < Config::MIN_NODES) {
            throw invalid_argument("Tamaño del conjunto inválido");
        }
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x < 0 || x >= static_cast<int>(parent.size())) {
            throw out_of_range("Índice fuera de rango");
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class NetworkOptimizer {
private:
    int numNodes;
    vector<vector<int>> distances;
    vector<vector<int>> capacities;
    vector<Point> centers;

    vector<vector<int>> readMatrix(const string& matrixName) {
        vector<vector<int>> matrix(numNodes, vector<int>(numNodes));
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (!(cin >> matrix[i][j])) {
                    throw runtime_error("Error leyendo " + matrixName);
                }
                if (matrix[i][j] < 0) {
                    throw invalid_argument(matrixName + " contiene valores negativos");
                }
            }
        }
        return matrix;
    }

    bool bfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
        vector<bool> visited(numNodes, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            for (int nextNode = 0; nextNode < numNodes; nextNode++) {
                if (!visited[nextNode] && residualGraph[currentNode][nextNode] > 0) {
                    q.push(nextNode);
                    parent[nextNode] = currentNode;
                    visited[nextNode] = true;
                }
            }
        }

        return visited[sink];
    }

public:
    NetworkOptimizer(int N) : numNodes(N) {
        if (N < Config::MIN_NODES || N > Config::MAX_NODES) {
            throw invalid_argument("Número de nodos fuera de rango válido");
        }
        
        try {
            Logger::logInfo("Leyendo matriz de distancias...");
            distances = readMatrix("Matriz de distancias");
            
            Logger::logInfo("Leyendo matriz de capacidades...");
            capacities = readMatrix("Matriz de capacidades");
            
            Logger::logInfo("Leyendo ubicaciones de centrales...");
            readCenters();
        } catch (const exception& e) {
            throw runtime_error(string("Error en inicialización: ") + e.what());
        }
    }

    void readCenters() {
        for (int i = 0; i < numNodes; i++) {
            double x, y;
            if (!(cin >> x >> y)) {
                throw runtime_error("Error leyendo coordenadas de central " + to_string(i + 1));
            }
            centers.emplace_back(x, y);
        }
    }

    vector<Edge> calculateOptimalCabling() {
        vector<Edge> edges;
        for (int i = 0; i < numNodes; i++) {
            for (int j = i + 1; j < numNodes; j++) {
                if (distances[i][j] > 0) {
                    edges.emplace_back(i, j, distances[i][j]);
                }
            }
        }

        vector<Edge> minimumSpanningTree;
        DisjointSet ds(numNodes);
        sort(edges.begin(), edges.end());

        for (const Edge& edge : edges) {
            if (ds.find(edge.sourceNode) != ds.find(edge.destinationNode)) {
                ds.unite(edge.sourceNode, edge.destinationNode);
                minimumSpanningTree.push_back(edge);
            }
        }

        return minimumSpanningTree;
    }

    vector<int> calculateDeliveryRoute() {
        vector<bool> visited(numNodes, false);
        vector<int> route;
        
        int currentPos = 0;
        route.push_back(currentPos);
        visited[currentPos] = true;

        for (int i = 0; i < numNodes - 1; i++) {
            int nextPos = -1;
            int minDistance = numeric_limits<int>::max();

            for (int j = 0; j < numNodes; j++) {
                if (!visited[j] && distances[currentPos][j] < minDistance) {
                    minDistance = distances[currentPos][j];
                    nextPos = j;
                }
            }

            if (nextPos == -1) {
                throw runtime_error("No se encontró ruta válida");
            }

            route.push_back(nextPos);
            visited[nextPos] = true;
            currentPos = nextPos;
        }

        route.push_back(0);  // Regresar al inicio
        return route;
    }

    int calculateMaxFlow() {
        vector<vector<int>> residualGraph = capacities;
        vector<int> parent(numNodes);
        int maxFlow = 0;
        int source = 0;
        int sink = numNodes - 1;

        while (bfs(residualGraph, source, sink, parent)) {
            int pathFlow = numeric_limits<int>::max();
            
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, residualGraph[u][v]);
            }

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }

    Point findNearestCenter(const Point& location) {
        if (centers.empty()) {
            throw runtime_error("No hay centrales disponibles");
        }

        Point nearest = centers[0];
        double minDistance = location.distanceTo(centers[0]);

        for (size_t i = 1; i < centers.size(); i++) {
            double distance = location.distanceTo(centers[i]);
            if (distance < minDistance) {
                minDistance = distance;
                nearest = centers[i];
            }
        }

        return nearest;
    }
};

void printRoute(const vector<int>& route) {
    for (int vertex : route) {
        cout << (char)('A' + vertex) << " ";
    }
    cout << endl;
}

void printCabling(const vector<Edge>& cabling) {
    for (const Edge& edge : cabling) {
        cout << "(" << (char)('A' + edge.sourceNode) 
             << ", " << (char)('A' + edge.destinationNode) << ") ";
    }
    cout << endl;
}

int main() {
    try {
        int N;
        if (!(cin >> N)) {
            throw runtime_error("Error leyendo número de colonias");
        }

        NetworkOptimizer optimizer(N);

        // 1. Kruskal - Encontrar el árbol de expansión mínima
        cout << "1. Conexiones de fibra óptica:" << endl;
        vector<Edge> mst = optimizer.calculateOptimalCabling();
        printCabling(mst);

        // 2. TSP - Encontrar la ruta para repartir correspondencia
        cout << "2. Ruta de reparto: ";
        vector<int> route = optimizer.calculateDeliveryRoute();
        printRoute(route);

        // 3. Ford-Fulkerson - Calcular el flujo máximo
        int maxFlow = optimizer.calculateMaxFlow();
        cout << "3. Flujo máximo: " << maxFlow << endl;

        // 4. Encontrar central más cercana para una nueva ubicación
        double x, y;
        if (!(cin >> x >> y)) {
            throw runtime_error("Error leyendo coordenadas de nueva ubicación");
        }
        Point newLocation(x, y);
        Point nearest = optimizer.findNearestCenter(newLocation);
        cout << "4. Central más cercana: " << nearest.toString() << endl;

    } catch (const exception& e) {
        Logger::logError(e.what());
        return 1;
    }

    return 0;
}