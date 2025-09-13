class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        double avg = accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
        int x = (int)avg + 1; // strictly greater than avg
        while (true) {
            if (x > 0 && st.find(x) == st.end()) return x;
            x++;
        }
    }
};
