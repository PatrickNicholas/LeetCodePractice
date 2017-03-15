class Solution {
public:
    typedef vector<vector<char>> matrix;
    
    bool checkValid(matrix &board) {
        for (int i = 0; i < 9; ++i) {
            vector<char> set1(10, 0);
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                if (set1[c - '0']++) return false;
            }
        }
        
        for (int j = 0; j < 9; ++j) {
            vector<char> set(10, 0);
            for (int i = 0; i < 9; ++i) {
                char c = board[i][j];
                if (c == '.') continue;
                if (set[c - '0']++) return false;
            }
        }
        
        for (int i = 0; i < 9; ++i) {
            vector<char> set(10, 0);
            int m = (i % 3) * 3, n = (i / 3) * 3;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    char c = board[m + j][n + k];
                    if (c == '.') continue;
                    if (set[c - '0']++) return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(matrix& board) {
        return checkValid(board);
    }
};