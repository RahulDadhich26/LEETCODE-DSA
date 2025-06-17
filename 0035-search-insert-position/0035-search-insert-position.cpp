class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int left = 0;
        // int right = nums.size() - 1;
        // while(left < right){
        //     int mid = low + (right - left)/2;
        //     if(nums[mid] == target) return mid;
        //     if()
        // }
        int i ;
        for(i=0;i<nums.size();i++){
            if(nums[i] >= target) return i;
        }
        return i;
    }
};