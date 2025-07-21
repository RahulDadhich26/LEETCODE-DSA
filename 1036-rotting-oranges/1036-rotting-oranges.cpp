class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
           int m = grid.size(), n = grid[0].size();   
                queue<pair<int, int>> q;            
                int fresh = 0;                   
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 2) {
                            q.push({i, j});            
                        } else if (grid[i][j] == 1) {
                            fresh++;                      
                        }
                    }
                }
                int time = 0;                    
                vector<int> dx = {0, 0, 1, -1};                      
                vector<int> dy = {1, -1, 0, 0};
                while (!q.empty() && fresh > 0) {                
                    int size = q.size();                         
                    while (size--) {
                        auto [x, y] = q.front(); q.pop();           
                        for (int dir = 0; dir < 4; ++dir) {  
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                                grid[nx][ny] = 2;        
                                q.push({nx, ny});      
                                fresh--;        
                            }
                        }
                    }
                    time++;         
                }
                return fresh == 0 ? time : -1; 
    }
};