class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return -1;
    int totalSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum += nums[i];
    }
    int leftSum = 0;
    for(int i = 0; i < n; i++) {
        if(leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
    }
};