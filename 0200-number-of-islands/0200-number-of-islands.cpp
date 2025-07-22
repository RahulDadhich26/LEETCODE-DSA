class Solution {
private:
    void bfs(int i, int j ,vector<vector<int>>& vis ,vector<vector<char>>& grid ){
        vis[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();

        // 4-directional movement
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nrow = row + dx[k];
                int ncol = col + dy[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                   grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};