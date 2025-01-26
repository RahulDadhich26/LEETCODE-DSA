class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefix_map;
        prefix_map[0] = 1; // Initialize with {0: 1}

        // Iterate through the array
        for (int num : nums) {
            sum += num; // Update the cumulative sum
            if (prefix_map.find(sum - k) != prefix_map.end()) {
                // If (sum - k) exists in the map, add its frequency to count
                count += prefix_map[sum - k];
            }
            // Update the frequency of the current sum in the map
            prefix_map[sum]++;
        }

        return count;
    }
};