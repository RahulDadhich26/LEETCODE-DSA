class Solution {
public:
    bool isPalindrome(int x) {
        int duplicate = x ;
        int rn = 0;
        while(x>0){
            int ld = x%10;
            rn = (rn*10)+ld;
            x/=10;
        }
        if(rn == duplicate) return true;
        return false;
    }
};