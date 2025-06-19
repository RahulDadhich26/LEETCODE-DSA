class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,j = 0;
        for( j=0;j<t.length();j++){
            if(i < s.length() && t[j] == s[i]){
                i++;
            }
        }
        return i == s.length(); 
    }
};