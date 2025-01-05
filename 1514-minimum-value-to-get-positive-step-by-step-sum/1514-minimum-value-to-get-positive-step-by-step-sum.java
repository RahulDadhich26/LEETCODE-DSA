class Solution {
    public int minStartValue(int[] nums) {
        if (nums == null) {
            throw new IllegalArgumentException("Input array is null");
        }

        int minVal = 0;
        int prefixSum = 0;

        for (int n : nums) {
            prefixSum += n;
            // Find the minimum prefix sum which is <= zero, as it will help us to find the lowest negative value.
            minVal = Math.min(minVal, prefixSum);
        }

        return 1 - minVal;
    }
}