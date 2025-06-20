class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ;
        int r = 0 ;
        int max_len = 0;
        vector<int>map(128,-1);
        while(r < s.size()){
            char cur = s[r];
            int index = map[cur];
            if(index != -1 && index >= l){
                l = index + 1;
            }
            int window_size = r - l + 1;
            max_len = max(max_len , window_size);
            map[cur] = r;
            r++;
        }
        return max_len;
    }
};