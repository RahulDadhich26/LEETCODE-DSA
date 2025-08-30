class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> numMap;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in the map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        
        // agar upar map me nhi mila to isko map me key banakar store kr do <-> Add current number to the map
        numMap[nums[i]] = i;
    }
        return {};
    }
};
