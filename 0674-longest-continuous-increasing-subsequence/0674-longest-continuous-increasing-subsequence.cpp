class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxc = 1;
        int count = 1;
        for(int i = 1 ; i< nums.size();i++){
            if(nums[i] > nums[i-1]){
                count++;
                maxc = max(maxc,count);
            }
            else{
                count = 1;
            }
        }
        return maxc;
    }
};