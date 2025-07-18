class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
    int i = n - 2;
    
    // Find first decreasing element from right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    
    if (i >= 0) {
        // Find element just larger than nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    
    // Reverse the suffix
    reverse(nums.begin() + i + 1, nums.end());
    }
};