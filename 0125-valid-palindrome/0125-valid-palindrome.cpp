class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n-1;
        while(left < right){
            while(left < right && !isalnum(s[left])) return left++;
            while(right > right && !isalnum(s[right])) return right--;

            if(tolower(s[left]) != tolower(s[right])) return false;

        left++;
        right--;
       
        }
         return true; 
    }
};