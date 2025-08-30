class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxc = 0;

        for(int num : nums){
            if(num == 1){
                count++;
                maxc = max(maxc, count);
            }
            else{
                count = 0;
            }
        }
        return maxc;
    }
};