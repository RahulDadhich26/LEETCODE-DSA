class Solution {
public:
    string decodeString(string s) {
     stack<char> st;
    for (char ch : s) {
        if (ch != ']') {
            st.push(ch);
        } else {
            string temp = "";
            while (!st.empty() && st.top() != '[') {
                temp = st.top() + temp;
                st.pop();
            }
            st.pop(); 
            string numStr = "";
            while (!st.empty() && isdigit(st.top())) {
                numStr = st.top() + numStr;
                st.pop();
            }
            int k = numStr.empty() ? 1 : stoi(numStr);
            string repeated = "";
            for (int i = 0; i < k; i++) {
                repeated += temp;
            }
            for (char c : repeated) {
                st.push(c);
            }
        }
    }
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
    }
};