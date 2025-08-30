class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxStreak = 1;
        int streak = 1;

        for(int i = 1 ; i<s.length();i++){
            if(s[i] - s[i-1] == 1){
                streak++;
                maxStreak = max(maxStreak,streak);
            }
            else{
                streak = 1;
            }
        }
        return maxStreak;
    }
};