class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;

        int l = 0, r = 0;
        int max_len = 0;

        while( r < s.size()){
            if(seen.find(s[r]) == seen.end()){
                seen.insert(s[r]);

                max_len = max(max_len, r-l+1);
                r++;
            }
            else {
                seen.erase(s[l]);
                l++;
            }
        }
        return max_len;
    }
};