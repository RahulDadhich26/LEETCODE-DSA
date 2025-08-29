class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int smallest = 1;
        for(int i : nums){
            if( i == smallest){
                smallest++;
            }
        }
        return smallest;
    }
};