class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && st.top() > num[i] && k != 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);  // Push everything, including '0'
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Use vector for efficient reverse building
        vector<char> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        // Remove leading zeros
        int i = 0;
        while (i < temp.size() && temp[i] == '0') {
            i++;
        }

        string ans(temp.begin() + i, temp.end());

        return ans.empty() ? "0" : ans;
    }
};