class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;

        for(int price : prices){
            minprice = min(minprice, price);
            maxprofit = max(maxprofit, price - minprice);
        }
        return maxprofit;
    }
};