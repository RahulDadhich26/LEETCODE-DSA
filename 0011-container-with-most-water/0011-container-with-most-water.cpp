class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;                      // Left pointer starts at the beginning
        int right = height.size() - 1;     // Right pointer starts at the end
        int maxWater = 0;                  // Variable to store the maximum water area
        
        while (left < right) {
            // Calculate the current water area
            int currentWater = (right - left) * min(height[left], height[right]);
            // Update maxWater if the current area is greater
            maxWater = max(maxWater, currentWater);
            
            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};