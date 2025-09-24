class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string ans = "";
        string s1 = strs[0];
        string s2 = strs[n-1];

         for(int i = 0; i < s1.size() && i < s2.size(); i++) {
            if(s1[i] == s2[i]) {
                ans += s1[i];
            } else {
                break;
            }
        }
        return ans;
    }
};