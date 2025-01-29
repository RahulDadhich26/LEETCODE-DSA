class Solution {
public:
    string minWindow(string s, string t) {
    if (s.size() < t.size()) {
        return "";
    }

    // Frequency map for characters in t
    unordered_map<char, int> targetMap;
    for (char c : t) {
        targetMap[c]++;
    }

    // Variables for the sliding window
    int left = 0, right = 0;
    int minLength = INT_MAX; // Track the minimum window length
    int minStart = 0;        // Starting index of the minimum window
    int required = targetMap.size(); // Number of unique characters in t
    int matchCount = 0;      // Number of characters matched so far

    // Frequency map for the current window
    unordered_map<char, int> windowMap;

    // Sliding window algorithm
    while (right < s.size()) {
        char currentChar = s[right];

        // Expand the window by including the current character
        if (targetMap.find(currentChar) != targetMap.end()) {
            windowMap[currentChar]++;
            if (windowMap[currentChar] == targetMap[currentChar]) {
                matchCount++;
            }
        }

        // Contract the window from the left if all characters are matched
        while (matchCount == required && left <= right) {
            // Update the minimum window
            int currentWindowLength = right - left + 1;
            if (currentWindowLength < minLength) {
                minLength = currentWindowLength;
                minStart = left;
            }

            // Move the left pointer to try a smaller window
            char leftChar = s[left];
            if (targetMap.find(leftChar) != targetMap.end()) {
                windowMap[leftChar]--;
                if (windowMap[leftChar] < targetMap[leftChar]) {
                    matchCount--;
                }
            }
            left++;
        }

        // Move the right pointer to expand the window
        right++;
    }

    // If no valid window is found, return an empty string
    return (minLength == INT_MAX) ? "" : s.substr(minStart, minLength);
    }
};