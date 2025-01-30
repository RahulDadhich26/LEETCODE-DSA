class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
         unordered_map<int, int> row_counts;
        unordered_map<int, int> col_counts;
        unordered_map<int, int> diag1_counts; // Diagonal: row + col
        unordered_map<int, int> diag2_counts; // Diagonal: row - col
        
        // Set to store the positions of active lamps
        unordered_set<long long> lamps_set;
        
        // Initialize the hash maps and set
        for (const auto& lamp : lamps) {
            int row = lamp[0];
            int col = lamp[1];
            long long key = (long long)row * n + col; // Unique key for each cell
            if (lamps_set.find(key) == lamps_set.end()) {
                lamps_set.insert(key);
                row_counts[row]++;
                col_counts[col]++;
                diag1_counts[row + col]++;
                diag2_counts[row - col]++;
            }
        }
        
        // Directions for 8 adjacent cells
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},  {0, 0},  {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        // Process each query
        vector<int> ans;
        for (const auto& query : queries) {
            int row = query[0];
            int col = query[1];
            
            // Check if the cell is illuminated
            if (row_counts[row] > 0 || col_counts[col] > 0 || diag1_counts[row + col] > 0 || diag2_counts[row - col] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
            
            // Turn off the lamp at (row, col) and its 8 adjacent lamps
            for (const auto& dir : directions) {
                int new_row = row + dir.first;
                int new_col = col + dir.second;
                long long key = (long long)new_row * n + new_col; // Unique key for each cell
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n && lamps_set.find(key) != lamps_set.end()) {
                    lamps_set.erase(key);
                    row_counts[new_row]--;
                    col_counts[new_col]--;
                    diag1_counts[new_row + new_col]--;
                    diag2_counts[new_row - new_col]--;
                }
            }
        }
        
        return ans;
    }
};