#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapS2T;
        unordered_map<char, char> mapT2S;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check s → t mapping
            if (mapS2T.count(c1) && mapS2T[c1] != c2) 
                return false;

            // Check t → s mapping
            if (mapT2S.count(c2) && mapT2S[c2] != c1) 
                return false;

            mapS2T[c1] = c2;
            mapT2S[c2] = c1;
        }
        return true;
    }
};
