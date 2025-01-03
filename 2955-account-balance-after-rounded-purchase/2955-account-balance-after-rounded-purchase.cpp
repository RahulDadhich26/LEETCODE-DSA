class Solution {
public:
    int accountBalanceAfterPurchase(int pA) {
        int x = pA % 10;
        int y = 10 - x ;
        int c = 0;
        if(x < y){
            c = pA - x ;
        }
        else{
            c = pA + y;
        }
        return (100 - c);
    }
};