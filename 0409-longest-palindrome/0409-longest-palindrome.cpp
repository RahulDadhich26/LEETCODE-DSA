class Solution {
public:
    int longestPalindrome(string s) {
         int map[128] = {0};
    
    for(char c : s) {
        map[c]++;
    }
    
    int oddCount = 0;
    
    for(int i = 0; i < 128; i++) {
        if(map[i] % 2 == 1) {
            oddCount++;
        }
    }
    
    if(oddCount > 0) {
        return s.size() - oddCount + 1;
    }
    
    return s.size();
    }
};