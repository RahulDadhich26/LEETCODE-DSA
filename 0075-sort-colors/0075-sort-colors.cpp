class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0; // low hai ye

        int med = 0 ; // ye mid h 

        int high = nums.size() - 1; // high last me h 
        
        int n = nums.size();
        while(med <= high){
            if(nums[med] == 0){
                swap(nums[low], nums[med]);
                low++;
                med++;
            }
            else if(nums[med] == 1){
                med++;
            }
            else {
                swap(nums[med],nums[high]);
                high--;
            }
        }
    }
};