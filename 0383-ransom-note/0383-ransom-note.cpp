class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         vector<int> count(26, 0);  // For 'a' to 'z'

    // Count frequency of each char in magazine
    for (char ch : magazine) {
        count[ch - 'a']++;
    }

    // Check ransomNote requirements
    for (char ch : ransomNote) {
        if (count[ch - 'a'] == 0) {
            return false;  // Not enough characters
        }
        count[ch - 'a']--;  // Use one occurrence
    }

    return true;
    }
};