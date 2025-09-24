class Solution {
public:
    int strStr(string haystack, string needle) {
        string str = needle;
        int idx = haystack.find(str);
        return idx;
    }
};