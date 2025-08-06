class Solution {
public:
    int longestBeautifulSubstring(string word) {
        string vowels = "aeiou";
        int state = -1;  // invalid state initially
        int currentLength = 0, maxLength = 0;

        for (int i = 0; i < word.size(); i++) {
            if (state == -1) {
                if (word[i] == 'a') {
                    state = 0;
                    currentLength = 1;
                }
                continue;
            }

            if (word[i] == vowels[state]) {
                currentLength++;
            } 
            else if (state < 4 && word[i] == vowels[state + 1]) {
                state++;
                currentLength++;
            } 
            else {
                if (word[i] == 'a') {
                    state = 0;
                    currentLength = 1;
                } else {
                    state = -1;
                    currentLength = 0;
                }
            }

            if (state == 4) {
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};