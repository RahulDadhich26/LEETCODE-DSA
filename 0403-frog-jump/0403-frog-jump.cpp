class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1)
        return false;

            if(stones.size()==2)
                return (stones[1]-stones[0]==1);
            
            vector<vector<long>> dp(stones.size(), vector<long> (stones.size()+1, -1));
            return func(1, 1, stones, dp);
        }

        bool func(int i, int jumps, vector<int> &stones, vector<vector<long>> &dp){
            if(i==stones.size()-1)
                return true;
                
            if(dp[i][jumps] != -1)
                return dp[i][jumps];
            
            bool ans=false;
            for(int ind=i+1; ind<stones.size(); ind++){
                if(stones[ind]-stones[i]>jumps+1)
                    break;
                for(int t=-1; t<2; t++){
                    if(stones[ind]-stones[i]==jumps+t)
                        ans = func(ind, jumps+t, stones, dp) || ans;
                }
            }

            return dp[i][jumps] = ans;
            }
};