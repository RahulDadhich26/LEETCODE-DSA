class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
    unordered_map<char, char> mapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : s) {
        if (mapping.count(ch)) { // If it's a closing parenthesis
            if (st.empty() || st.top() != mapping[ch]) {
                return false; // Unbalanced
            }
            st.pop(); // Pop the matching opening parenthesis
        } else if (ch == '(' || ch == '[' || ch == '{') { // If it's an opening parenthesis
            st.push(ch); // Push onto the stack
        }
    }

    return st.empty();
    }
};