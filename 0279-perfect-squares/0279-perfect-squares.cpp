 class Solution {
public:
    int numSquares(int n) {
        std::vector<int> memo(n + 1, INT_MAX);
        memo[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j*j <= i; ++j) {
                memo[i] = std::min(memo[i], 1 + memo[i - j*j]);
            }
        }
        
        return memo[n];
    }
};