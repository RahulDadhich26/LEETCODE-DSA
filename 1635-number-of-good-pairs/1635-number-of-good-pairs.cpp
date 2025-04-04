class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int total = 0;
        for(auto i:nums){
            mpp[i]++;
        }
        for(auto i : mpp){
            int count = i.second;
            total += count * (count - 1) / 2;
        }
        return total;
    }
};