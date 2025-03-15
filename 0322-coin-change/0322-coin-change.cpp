class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
         vector<int>dp(sum+1, INT_MAX);
        dp[0] = 0;
        for(int coin:coins){
            for(int i=coin;i<=sum;i++){
            if(dp[i-coin] != INT_MAX){
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
            }
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};