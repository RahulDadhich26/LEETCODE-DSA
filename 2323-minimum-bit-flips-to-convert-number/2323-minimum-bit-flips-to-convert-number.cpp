class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int x = start ^ goal;

        while(x){
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }
};