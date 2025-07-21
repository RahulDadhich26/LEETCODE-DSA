class Solution {
public:
   int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;  // (1) Start or end blocked
    queue<pair<int, int>> q;
    q.push({0, 0});                                        // (2) Start BFS from (0,0)
    grid[0][0] = 1;                                        // (3) Mark step count directly in grid
                                                  
    vector<int> dx = {-1,-1,-1, 0, 0, 1, 1, 1};   // (4) 8 directions — Up, Down, Left, Right + Diagonals
    vector<int> dy = {-1, 0, 1, -1,1,-1, 0, 1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int dist = grid[x][y];

        if (x == n - 1 && y == n - 1) return dist;         // (5) Reached destination

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                grid[nx][ny] = dist + 1;                  // (6) Store distance directly
                q.push({nx, ny});
            }
        }
    }

    return -1;                                            // (7) Destination not reachable
  }
};