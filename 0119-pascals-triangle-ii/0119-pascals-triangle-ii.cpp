class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1); // First row is always [1]

        for (int i = 1; i <= rowIndex; ++i) {
            // Traverse from end to start to avoid overwriting values
            for (int j = res.size() - 1; j >= 1; --j) {
                res[j] = res[j] + res[j - 1];
            }
            res.push_back(1); // Add 1 at the end for the new row
        }

        return res;
    }
};