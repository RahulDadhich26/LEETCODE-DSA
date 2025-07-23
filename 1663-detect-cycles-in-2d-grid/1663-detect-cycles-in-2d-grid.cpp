class Solution {
public:
    bool dfs(int x, int y, int fromX, int fromY,vector<vector<char>>& grid,vector<vector<bool>>& vis, char color){
        int n = grid.size();
        int m = grid[0].size();

        vis[x][y] = true;
        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {1,-1,0,0};

        for(int dir = 0 ; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == color){

                if(!vis[nx][ny]) {
                    if(dfs(nx,ny,x,y,grid,vis,color)) return true;
                }
                else if(nx != fromX || ny != fromY){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0 ;i<n;i++){
            for(int j = 0; j<m;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,grid,visited,grid[i][j])) return true;
                }
            }
        }
     return false;
    }
};