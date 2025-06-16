class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Apply n-1 operations sequentially
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        // Shift all zeros to the end
        int writeIndex = 0;
        
        // First pass: move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }
        
        // Second pass: fill the remaining positions with zeros
        while (writeIndex < n) {
            nums[writeIndex] = 0;
            writeIndex++;
        }
        
        return nums;
    }
};