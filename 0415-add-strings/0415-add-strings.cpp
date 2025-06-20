class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() -1;
        int j = num2.size() - 1;

        int carry = 0;
        string result = "";
        while(i>=0 || j >=0 || carry > 0){
            int d1 = (i >= 0) ? (num1[i] - '0') : 0;
            int d2 = (j >= 0) ? (num2[j] - '0') : 0;
            int sum = d1 + d2 + carry;
            result = char(sum % 10  + '0') + result;
            carry = sum / 10; 
            i--;
            j--;
        }
        return result;
    }
};