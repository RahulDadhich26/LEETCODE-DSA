class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0;
        int count = 0;
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; // Initialize with {0: -1}

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Update count
            if (nums[i] == 0) {
                count--;
            } else {
                count++;
            }

            // Check if count exists in prefix_map
            if (prefix_map.find(count) != prefix_map.end()) {
                // Calculate subarray length
                max_len = max(max_len, i - prefix_map[count]);
            } else {
                // Store the first occurrence of count
                prefix_map[count] = i;
            }
        }

        return max_len;
    }
};