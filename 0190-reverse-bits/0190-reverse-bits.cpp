class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;        // left shift answer by 1
            ans |= (n & 1);   // add the last bit of n to ans
            n >>= 1;          // right shift n by 1
        }
        return ans;
    }
};