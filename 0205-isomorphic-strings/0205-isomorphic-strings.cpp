class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check s → t mapping
            if (m1.count(c1) && m1[c1] != c2) 
                return false;

            // Check t → s mapping
            if (m2.count(c2) && m2[c2] != c1) 
                return false;

            m1[c1] = c2;
            m2[c2] = c1;
        }
        return true;
    }
};
