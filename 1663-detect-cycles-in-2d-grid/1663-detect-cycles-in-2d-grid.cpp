class Solution {
public:
     bool containsCycle(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return false;
        
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    if (bfs(grid, visited, i, j, directions)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
private:
    bool bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int startRow, int startCol, vector<vector<int>>& directions) {
        
        queue<vector<int>> q; // {row, col, parentRow, parentCol}
        q.push({startRow, startCol, -1, -1});
        visited[startRow][startCol] = true;
        char ch = grid[startRow][startCol];
        
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            
            int row = curr[0], col = curr[1];
            int parentRow = curr[2], parentCol = curr[3];
            
            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < grid.size() && 
                    newCol >= 0 && newCol < grid[0].size() && 
                    grid[newRow][newCol] == ch) {
                    
                    // Skip parent
                    if (newRow == parentRow && newCol == parentCol) {
                        continue;
                    }
                    
                    // If visited and not parent, cycle found
                    if (visited[newRow][newCol]) {
                        return true;
                    }
                    
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol, row, col});
                }
            }
        }
        return false;
    }
};
