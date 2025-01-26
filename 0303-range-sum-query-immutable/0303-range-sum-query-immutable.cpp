class NumArray {
public:
    private:
    vector<int> prefix; // Prefix sum array
public:
    // Constructor: Preprocess the input array to build the prefix sum array
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        prefix[0] = nums[0]; // Initialize the first element
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i]; // Build the prefix sum array
        }
    }

    // Method to return the sum of elements between indices left and right (inclusive)
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix[right]; // Edge case: sum from index 0 to right
        }
        return prefix[right] - prefix[left-1]; // General case
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */