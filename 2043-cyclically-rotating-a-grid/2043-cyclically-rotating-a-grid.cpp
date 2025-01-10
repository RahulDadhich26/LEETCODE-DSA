class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() ; // row
        int n = grid[0].size() ; // column
        int ll = min(n , m) / 2;
        for(int l =0 ;l<ll;l++){
            vector<int>v ;
            for(int i=l;i<n-l-1;++i) v.push_back(grid[l][i]);  // top row
            for(int i=l;i<m-l-1;++i) v.push_back(grid[i][n - l - 1]);  // right column
            for(int i=n-l-1;i>l;--i) v.push_back(grid[m-l-1][i]);  // bottom row
            for(int i=m-l-1;i>l;--i) v.push_back(grid[i][l]);  // left column
            int start = k % v.size() ;
             for(int i = l; i < n - l - 1; ++i) // top row
                grid[l][i] = v[start++ % v.size()];
            for(int i = l; i < m - l - 1; ++i) // right
               grid[i][n - l - 1] = v[start++ % v.size()];
            for(int i = n - l - 1; i > l; --i) // bottom row
                grid[m - l - 1][i] = v[start++ % v.size()];
            for(int i = m - l - 1; i > l; --i) // left
                grid[i][l] = v[start++ % v.size()];
            }
        return grid;
    }
};