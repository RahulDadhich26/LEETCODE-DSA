class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // step 1 = build the adjacency list
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        // step 2 : dijkstra's algo
        vector<int>dist(n+1,1e9);
        dist[k] = 0;

       // min heap 
       // {time,node}
       priority_queue<  pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
       pq.push({0,k});
       
       while(!pq.empty()){
        pair<int,int>top = pq.top(); 
        pq.pop();

        int time = top.first;
        int node = top.second;

        if(time > dist[node]) continue;
        
        for(int i = 0 ; i < adj[node].size() ; i++){
            int v = adj[node][i].first;
            int w = adj[node][i].second;

            if(dist[node] + w < dist[v]){
                dist[v] = dist[node] + w;
                pq.push(make_pair(dist[v],v));
            }
        }
       }
       int ans = 0;
        for(int i = 1; i<= n ;i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};