// Algoritmo de Ford-Fulkerson
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    
    return visited[t];
}