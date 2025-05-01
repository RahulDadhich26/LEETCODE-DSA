class Solution {
public:
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> countIndex;
    countIndex[0] = -1;  // Base case to handle subarrays starting at index 0
    int maxlen = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        count += (nums[i] == 1) ? 1 : -1;

        if (countIndex.find(count) != countIndex.end()) {
            maxlen = max(maxlen, i - countIndex[count]);
        } else {
            countIndex[count] = i;
        }
    }

    return maxlen;
}
};