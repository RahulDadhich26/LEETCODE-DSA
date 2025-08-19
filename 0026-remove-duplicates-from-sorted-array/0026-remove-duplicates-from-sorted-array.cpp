class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       unordered_set<int>s;
       int idx = 0;
       for(int i = 0 ; i < nums.size() ;i++){
           if(s.find(nums[i]) == s.end()) {
               s.insert(nums[i]);
               nums[idx] = nums[i];
               idx++;
           }
       }
       return s.size();
    }
};