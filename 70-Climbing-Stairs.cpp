class Solution {
public:
    typedef vector<vector<int>> matrix;
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 0) return 0;
        if (n == 2) return 2;
        
        matrix a = { { 1, 1 }, { 1, 0 } };
        matrix b = { { 2 }, { 1 } };
        matrix c = pow(a, n-2);
        matrix d = mul(c, b);
        return d[0][0];
    }
    
    matrix mul(matrix &a, matrix &b) {
        matrix c(a.size(), vector<int>(b[0].size(), 0));
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                int result = 0;
                for (int k = 0; k < a[0].size(); ++k) {
                    result += a[i][k] * b[k][j];
                }
                c[i][j] = result;
            }
        }
        return c;
    }
    
    matrix pow(matrix a, int n) {
        matrix result(a.size(), vector<int>(a[0].size(), 0));
        for (int i = 0; i < a.size(); ++i) result[i][i] = 1;
        while (n > 0) {
            if (n & 1) result = mul(result, a);
            a = mul(a, a);
            n >>= 1;
        }
        return result;
    }
};
