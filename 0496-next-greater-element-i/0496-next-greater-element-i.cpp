class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int>s;
    unordered_map<int,int>nextGreater;
    for (int num : nums2) {
        while (!s.empty() && num > s.top()) {
            nextGreater[s.top()] = num; // Set the next greater element
            s.pop();
        }
        s.push(num);
    }
    while (!s.empty()) {
        nextGreater[s.top()] = -1;
        s.pop();
    }
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater[num]);
    }

    return result;
    }
};