class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
    
    // Last se check karo odd digit
    for(int i = n - 1; i >= 0; i--) {
        if(num[i] % 2 == 1) {  // Character ko directly check
            return num.substr(0, i + 1);
        }
    }
    
    return "";
    }
};