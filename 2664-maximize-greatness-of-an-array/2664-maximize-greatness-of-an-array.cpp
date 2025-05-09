class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
          sort(nums.begin(), nums.end());
        int i = 0, j = 0, n = nums.size();
        while (i < n && j < n) {
            if (nums[j] > nums[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};