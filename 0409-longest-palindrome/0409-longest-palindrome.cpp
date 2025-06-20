class Solution {
public:
    int longestPalindrome(string s) {
        int map[128] = {0};
        int odd = 0;
        for(auto m : s){
            map[m]++;
            if(map[m] % 2 == 1) odd++;
            else odd--;
        }
        if(odd >= 1) return s.size() - odd + 1;
        return s.size() ;
    }
};