class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIndex = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }
        for(int i=writeIndex;i<nums.size();i++){
             nums[writeIndex] = 0;
             writeIndex++;
        }
    }
};