class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1/x;
            n = abs(n);
        }
        unsigned c = n;
        double result = 1.0;
        while (c > 0) {
            if (c & 0x1) {
                result *= x;
            }
            c >>= 1;
            x = x * x;
        }
        return result;
    }
    
    
};
