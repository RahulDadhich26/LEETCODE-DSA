class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // count
        // index
        // i'm using count and index to inplace elements of the array
        // count them first
        int occurance = 1; 
        int index = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                occurance++;
            }
            else {
                occurance = 1;
            }
            if(occurance <= 2){
            nums[index] = nums[i];
            index++;
        }
        }
        return index;
    }
};