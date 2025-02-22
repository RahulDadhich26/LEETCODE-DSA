class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int mxln = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    mxln = max(mxln , i - st.top());
                }
            }
        }
        return mxln;
    }
};