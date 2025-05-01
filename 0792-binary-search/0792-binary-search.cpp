class Solution {
public:
    
    int binaryS(vector<int>& nums, int target, int low, int high){
        if(low > high) return -1;
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return binaryS(nums,target,mid+1,high);
        else return binaryS(nums,target,low,mid-1);
    }
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size() - 1;
        return binaryS(nums,target,low,high);
    }
};