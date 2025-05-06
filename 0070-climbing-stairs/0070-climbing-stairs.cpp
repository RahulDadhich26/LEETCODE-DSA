class Solution {
public:
    int climbStairs(int n) {
        int p = 1;
        int p2 = 1;
        for(int i=2;i<=n;i++){
            int curr = p + p2;
            p2= p;
            p = curr;
        }
        return p;
    }
};