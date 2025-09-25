class Solution {
public:
    string reverseWords(string s) {
            string t = trimSpaces(s);
        reverse(t.begin(), t.end());
        int n = t.size(), start = 0;
        for (int end = 0; end <= n; end++) {
            if (end == n || t[end] == ' ') {
                reverse(t.begin() + start, t.begin() + end);
                start = end + 1;
            }
        }
        return t;    
    }
        string trimSpaces(const string &s) {
        string r;
        int n = s.size(), i = 0;

        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            if (s[i] != ' ') r += s[i];
            else if (!r.empty() && r.back() != ' ') r += ' ';
            i++;
        }

        if (!r.empty() && r.back() == ' ') r.pop_back();
        return r;
        }

};