class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);  // for magazine letters

        // Count characters in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Check ransomNote requirements
        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0) return false;  // not enough letters
            freq[c - 'a']--;
        }

        return true;
    }
};