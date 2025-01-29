class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() < k) return 0;
        double windowSum = 0 ;
        for(int i=0;i<k;i++){
            windowSum+=nums[i];
        } 
        double maxsum = windowSum;
        for(int i=k ;i<nums.size();i++){
            windowSum = windowSum - nums[i-k] + nums[i];
            maxsum = max(maxsum , windowSum);
        }
        return maxsum/k;
    }
};