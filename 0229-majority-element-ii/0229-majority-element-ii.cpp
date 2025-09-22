
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> result;
        for (auto& entry : freq) {
            if (entry.second > n / 3) {
                result.push_back(entry.first);
            }
        }
        return result;
    }
};