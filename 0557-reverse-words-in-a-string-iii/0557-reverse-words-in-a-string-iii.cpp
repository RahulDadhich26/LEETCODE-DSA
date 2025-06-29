class Solution {
public:
    string reverseWords(string str) {
    stack<char> st;
    string result = "";
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        // Skip multiple spaces
        if (str[i] == ' ' && (i == 0 || str[i - 1] == ' ')) {
            continue;
        }
        if (str[i] != ' ') {
            st.push(str[i]);  // Push characters of a word
        } else {
            // Reverse the word
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            result += ' ';  // Add space after word
        }
    }
    // Add last word
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    // Trim trailing space if any
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
    }
};