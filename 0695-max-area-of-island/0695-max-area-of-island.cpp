class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // Boundary check और water check
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        
        // Current cell को visited mark करते हैं
        grid[i][j] = 0;
        
        // 4 directions में explore करते हैं और area calculate करते हैं
        return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + 
                   dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }
};