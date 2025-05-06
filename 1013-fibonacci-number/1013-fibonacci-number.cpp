class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
       int prev2 = 0 ;
       int prev = 1;
       for(int i=2;i<=n;i++){
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
       }
       return prev;
    }
    
};