class Solution {
public:
    int maxPower(string s) {
        int maxc = 1, count = 1;

        for(int i = 1 ; i < s.length();i++){
           if(s[i] == s[i-1]){
            count++;
            maxc = max(maxc,count);
           }
           else{
            count= 1;
           }
        }
        return maxc;
    }
};