class Solution {
public:
 void help(vector<int> nums, vector<int> res, vector<vector<int>>& ans, int i){
        if(i>=nums.size()){
            ans.push_back(res);
            return;
        }
        
        help(nums, res, ans, i+1); // Exclude nums[i]

        res.push_back(nums[i]); // Include nums[i]
        help(nums, res, ans, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
        vector<int> res;
        help(nums, res, ans, 0);
        return ans;
    
    }
};