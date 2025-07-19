class Solution {
public:
    vector<vector<int>>result;
    void backtrack(vector<int>&nums, vector<bool>&visited, vector<int>&temp){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(visited[i] == true) continue;

            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, visited, temp);
            visited[i] = false;
            temp.pop_back();

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int>temp;
        backtrack(nums,visited,temp);
        return result;
    }
};