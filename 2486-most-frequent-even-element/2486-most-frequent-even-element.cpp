class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(int num : nums){
            if(num % 2 == 0){
                mpp[num]++;
            }
        }

        if(mpp.empty()) return -1;
        
        int ans = -1, max_freq = 0;
        
        for(auto &entry : mpp){
            int num = entry.first;
            int count = entry.second;

            if(count > max_freq || (count == max_freq && num < ans)){
                max_freq = count;
                ans = num;
            }
        }
       return ans;
    }
};