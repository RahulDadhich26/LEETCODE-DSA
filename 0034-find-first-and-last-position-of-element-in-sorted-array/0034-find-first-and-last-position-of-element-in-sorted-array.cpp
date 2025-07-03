class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int starting_index = -1 ;
        int last_index = -1 ;
        int n = nums.size() ;
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                starting_index = i ;
                break ;
            }
        }
        for(int i= n-1;i>=0 ;i--){
            if(nums[i] == target){
                last_index = i ;
                break ;
            }
        }
        return {starting_index , last_index} ;
    }
};