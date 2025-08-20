
class Solution {
public:
    double helper(double x, long n) {
        if (n == 0) return 1.0;

        if (n % 2 == 0) {
            return helper(x * x, n / 2);
        } else {
            return x * helper(x * x, n / 2);
        }
    }

    double myPow(double x, int n) {
        long N = n; // promote to long to avoid overflow
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        return helper(x, N);
    }
};
