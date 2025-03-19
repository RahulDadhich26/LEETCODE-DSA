class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector<int>after(2*k+1 , 0) , cur(2*k+1 , 0);
       for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int transNo = 2*k - 1 ;transNo>=0 ;transNo--){
            if(transNo % 2 == 0){
                cur[transNo] = max( -prices[ind] + after[transNo + 1] , after[transNo]) ;
            }
            else{
                cur[transNo] = max(prices[ind] + after[transNo + 1] , after[transNo]) ;
            }
        }
        after = cur ;
    }
    return after[0] ;
    }
};