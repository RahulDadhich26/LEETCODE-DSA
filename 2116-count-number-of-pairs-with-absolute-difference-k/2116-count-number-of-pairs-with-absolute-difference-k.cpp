class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int count = 0;

        for(int num : nums){
            if(mpp.count(num - k)) count += mpp[num - k];

            if(mpp.count(num + k)) count += mpp[num + k];

            mpp[num]++;
        }

        return count;
        
    }
};