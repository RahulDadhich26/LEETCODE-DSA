class Solution {
public:
    int WithKDistinct(vector<int>& nums, int k) {
        int l = 0 , r = 0, maxcnt = 0;
        unordered_map<int,int>mpp;
        while(r < nums.size()){
           mpp[nums[r]]++;

          while(mpp.size() > k){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }
            l++;
          }
          maxcnt = maxcnt + (r - l + 1);
          r++;
        }
        return maxcnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return WithKDistinct(nums,k) - WithKDistinct(nums,k-1);
    }
};