class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(auto ch : columnTitle){
            int a = ch - 64;
            ans = ans * 26 + a;
        }
        return ans;
    }
};