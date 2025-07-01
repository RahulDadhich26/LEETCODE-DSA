class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, prevPrev = 0;
    
    for (int num : nums) {
        int current = max(prev, prevPrev + num);
        prevPrev = prev;
        prev = current;
    }
    
    return prev;
    }
};