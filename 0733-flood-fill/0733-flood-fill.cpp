class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, int oldColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Boundary or different color? Stop.
        if (row < 0 || col < 0 || row >= n || col >= m || image[row][col] != oldColor)
            return;

        image[row][col] = newColor;

        dfs(row + 1, col, image, oldColor, newColor);  // down
        dfs(row - 1, col, image, oldColor, newColor);  // up
        dfs(row, col + 1, image, oldColor, newColor);  // right
        dfs(row, col - 1, image, oldColor, newColor);  // left
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];

        if (oldColor != newColor) {
            dfs(sr, sc, image, oldColor, newColor);
        }

        return image;
    }
};