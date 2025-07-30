class Solution {
public:
    int climbStairs(int n) {
        int p1 = 1;
        int p2 = 1;
        for(int i=2;i<=n;i++){
            int curr = p1 + p2;
            p2= p1;
            p1 = curr;
        }
        return p1;
    }
};