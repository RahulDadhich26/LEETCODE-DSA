class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1); // First row is always [1]

        for (int i = 1; i <= rowIndex; ++i) {
            // Traverse from end to start to avoid overwriting values
            for (int j = i - 1; j >= 1; --j) {
                res[j] = res[j] + res[j - 1];
            }
            res.push_back(1); // Add 1 at the end for the new row
        }

        return res;
    }
};

/*

res = [1, 3, 3, 1]
// inner loop:
j = 3 → res[3] = res[3] + res[2] = 1 + 3 = 4
→ res = [1, 3, 3, 4]
j = 2 → res[2] = res[2] + res[1] = 3 + 3 = 6
→ res = [1, 3, 6, 4]
j = 1 → res[1] = res[1] + res[0] = 3 + 1 = 4
→ res = [1, 4, 6, 4]
res.push_back(1) → res = [1, 4, 6, 4, 1]

*/