class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // Count the number of break points where nums[i] > nums[i+1]
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        // A valid rotated sorted array can have at most 1 break point
        return count <= 1;
    }
};