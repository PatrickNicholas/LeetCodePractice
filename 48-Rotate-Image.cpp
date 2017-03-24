class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        for (int i = 0; i < N / 2; ++i) {
            int beg = i, end = N - 1 - i;
            for (int j = beg; j < end; ++j) {
                int top = matrix[beg][j];
                matrix[beg][j] = matrix[end - j + beg][beg];
                matrix[end - j + beg][beg] = matrix[end][end - j + beg];
                matrix[end][end - j + beg] = matrix[j][end];
                matrix[j][end] = top;
            }
        }
    }
};
