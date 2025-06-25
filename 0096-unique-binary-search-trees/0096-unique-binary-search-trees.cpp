class Solution {
public:
    int numTrees(int n) {
        int i=n*2;
        int j=1;
        long ans = 1;
        while(i!=n){
        ans = ans*i/j;
        i--;
        j++;
        }
        return ans/(n+1);
    }
};