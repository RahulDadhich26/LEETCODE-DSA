class Solution {
public:
    bool checkDivisibility(int n) {
           string s = to_string(n);
        int sum = 0, mul=1;
        for(int i=0; i<s.length(); i++){
            int digit = stoi(string(1,s[i]));
            sum += digit;

            mul = mul*digit;
        }
        return n%(sum + mul) == 0;
    }
};