class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++){
            if(st.count(nums[i])) return true;   // duplicate found in last k elements
            st.insert(nums[i]);                  // add current number

            if(st.size() > k) {
                st.erase(nums[i - k]);           // remove oldest element to maintain window of size k
            }
        }

        return false;
    }
};