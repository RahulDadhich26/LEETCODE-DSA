class Solution {
public:
    string reverseWords(string s) {
         stack<string> st;
    string str = "";
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            if(!str.empty()) {  // Empty strings avoid karne ke liye
                st.push(str);
                str = "";
            }
        }
        else{
            str += s[i];
        }
    }
    
    // Last word ko push karna zaruri hai
    if(!str.empty()) {
        st.push(str);
    }
    
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
        if(!st.empty()) {  // Last word ke baad space nahi chahiye
            ans += " ";
        }
    }
    
    return ans;
    }
};