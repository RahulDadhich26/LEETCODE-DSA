class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0 ;
        string ans = "";
        while(i >= 0 || j>=0 || carry){
            if( i>=0 ){
                carry += (a[i] - 48);
                i--;
            }
            if(j >= 0){
                carry += (b[j] -48);
                j--;
            }
            char dig = (carry % 2) + 48;
            ans = dig + ans;
            carry/=2;
        }
        return ans;
    }
};