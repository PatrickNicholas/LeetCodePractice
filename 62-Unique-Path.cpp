class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m + n - 2;
        m = min(m, n);
        long long int a = 1, b = 1;
        for (int i = total; i > total-m+1; i--) a *= i;
        for (int i = 1; i < m; ++i) b *= i;
        return a / b;
    }
};
