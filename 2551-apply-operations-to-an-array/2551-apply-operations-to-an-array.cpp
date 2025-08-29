class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
         for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move zeros to the end
            vector<int> result;
            for (int x : nums) {
                if (x != 0) result.push_back(x);
            }
            while (result.size() < n) {
                result.push_back(0);
            }

            return result;
    }
};