class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&adj) {
        int n=adj.size();
        vector<vector<int>>check(n);
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                check[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:check[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;        
    }
};