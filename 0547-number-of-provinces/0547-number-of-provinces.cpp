class Solution {
private:
    void dfs(int node, vector<int> adjLs[], vector<int>& vis) {
        vis[node] = 1;
        for(auto it : adjLs[node]) {
            if(!vis[it]) dfs(it, adjLs, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> adjLs[V];  // Array of vectors for adjacency list
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;  // Initialize count variable
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};