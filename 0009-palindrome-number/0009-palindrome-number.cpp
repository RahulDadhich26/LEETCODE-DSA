class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 || (x % 10 == 0 && x != 0)) return false;

        int original = x;
        long long int rev = 0;
        while(x > 0){
             int ld = x % 10;
             rev = rev * 10 + ld;
             x/=10;
        }  
        return (rev == original);
    }
};