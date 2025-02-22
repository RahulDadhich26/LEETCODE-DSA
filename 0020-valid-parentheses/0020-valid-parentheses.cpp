class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mapping = {
              {']','['},
              {')','('},
              {'}','{'}
        };
        for(char ch : s){
            if(mapping.count(ch)){
                if(st.empty() || st.top()!= mapping[ch]){
                    return false;
                }
                st.pop();
            }
            else if(ch == '{' || ch == '[' || ch == '('){
                st.push(ch);
            }
        }
        return st.empty();
    }
};