class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return ;
        
        vector<int> count(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            bool hasZero = false;
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    count[j] = 1;
                    hasZero = true;
                }
            }
            if (!hasZero) continue;
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (!count[i]) continue;
            for (int j = 0; j < matrix.size(); ++j) {
                matrix[j][i] = 0;
            }
        }
    }
};
