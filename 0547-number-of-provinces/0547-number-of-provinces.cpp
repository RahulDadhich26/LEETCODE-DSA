class Solution {
private:
    void dfs(int node, vector<int> adjLs[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adjLs[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjLs, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();  // Number of cities/nodes
        vector<int> adjLs[V];

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i); // undirected
                }
            }
        }

        vector<bool> visited(V, false);
        int provinces = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                ++provinces;
                dfs(i, adjLs, visited);
            }
        }

        return provinces;
    }
};