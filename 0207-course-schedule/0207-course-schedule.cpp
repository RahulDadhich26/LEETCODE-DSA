class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
         vector<int>adj[V];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(V, 0);
    
        // 2. Calculate indegrees
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
    
        // 3. Queue all nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
    
        // 4. BFS process
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
    
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
    
        return topo.size() == V;
    }
};