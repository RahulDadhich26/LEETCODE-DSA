// Directory: /leetcode/strings/
// Dependencies: <bits/stdc++.h>

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result += (sum % 2) + '0';  // store bit
            carry = sum / 2;            // update carry
        }

        reverse(result.begin(), result.end());
        return result;
    }
};