class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return 0;
        if(nums.size() == 2){

        }
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == n-1 || nums[mid] > nums[mid+1])){
                return mid;
            }
            else if(nums[mid] < nums[mid+1]){
                left = mid + 1;
            }
            else {
             right = mid - 1;
            }
        }
        return -1;
    }
};