class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int last_price= prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > last_price){
                int curr_profit = prices[i] - last_price;
                max_profit = max(max_profit,curr_profit);
            }
            else{
                last_price = prices[i];
            }
        }
        return max_profit;
    }
};