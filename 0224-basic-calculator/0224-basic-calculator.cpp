class Solution {
public:
     int calculate(string s) {
        long long result = 0;   // current accumulated result
        long long number = 0;   // current number being built
        int sign = 1;           // current sign: +1 or -1
        stack<long long> st;    // store previous result and sign (in that order)

        for (int i = 0; i < (int)s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (c == '(') {
                // push current state and start fresh inside parentheses
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * number;
                number = 0;
                int prevSign = (int)st.top(); st.pop();
                long long prevResult = st.top(); st.pop();
                result = prevResult + prevSign * result;
            } else {
                // skip spaces or any other chars
            }
        }

        // add leftover number
        result += sign * number;
        return (int)result;
    }
};