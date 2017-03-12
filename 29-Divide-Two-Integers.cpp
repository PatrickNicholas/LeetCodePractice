class Solution {
public:
    typedef long long ll;
    
    int divide(int n_, int d_) {
        ll ans = 0, n = n_, d = d_;
        if (n_ < 0) n = -n;
        if (d_ < 0) d = -d;
        while (n >= d) {
            ll a = d;
            ll m = 1;
            while ((a << 1) < n) {
                a <<= 1;
                m <<= 1;
            }
            ans += m;
            n -= a;
        }
        if ((n_ < 0 && d_ >= 0) || (n_ >= 0 && d_ < 0)) {
            if (INT_MIN > -ans)
                return INT_MIN;
            return -ans;
        }
        if (INT_MAX < ans)
            return INT_MAX;
        return ans;
    }
};
