class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x; 
        if(n == -1)
            return 1/x;
        double halfPower = myPow(x,n/2);
        double result = halfPower * halfPower;

        if(n%2 != 0)
        {
            if(n > 0)
                result = result * x;
            else
                result = result / x;
        }
        return result;
    }
};