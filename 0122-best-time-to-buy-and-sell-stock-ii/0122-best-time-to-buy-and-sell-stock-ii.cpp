class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        for(int i=1;i<prices.size();i++){
           if(prices[i-1] < prices[i]) mp += prices[i] - prices[i-1];
        }
        return mp;
    }
};