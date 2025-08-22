class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        unordered_map<char,int> target;
        for(char c : t) target[c]++;

        unordered_map<char,int> window_counts;
        int required = target.size();
        int formed = 0;

        int l = 0, r = 0;
        int min_len = INT_MAX, start = 0;

        while(r < s.size()){
            char c = s[r];
            window_counts[c]++;

            if(target.count(c) && window_counts[c] == target[c])
                formed++;

            while(l <= r && formed == required){
                if(r - l + 1 < min_len){
                    min_len = r - l + 1;
                    start = l;
                }

                char left_char = s[l];
                window_counts[left_char]--;
                if(target.count(left_char) && window_counts[left_char] < target[left_char])
                    formed--;
                l++;
            }
            r++;
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};