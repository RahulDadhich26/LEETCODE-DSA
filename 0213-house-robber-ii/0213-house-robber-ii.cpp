class Solution {
public:
int robLinear(vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0;
    for (int i = start; i <= end; ++i) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    // Case 1: Rob houses from 0 to n-2 (excluding the last house)
    int case1 = robLinear(nums, 0, n - 2);
    
    // Case 2: Rob houses from 1 to n-1 (excluding the first house)
    int case2 = robLinear(nums, 1, n - 1);
    
    // Return the maximum of the two cases
    return max(case1, case2);
}
};