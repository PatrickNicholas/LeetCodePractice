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
        return checkValid(board) && find(board, 0, 0);
    }
    
    bool find(matrix &board, int x, int y) {
        bool result = true;
        for (int i = x; i < board.size(); ++i) {
            for (int j = y; j < board[0].size(); ++j) {
                if (board[i][j] != '.')
                    continue;
                result = false;
                vector<char> usable = findUsable(board, i, j);
                for (int c = 0; c < 10; ++c) {
                    if (usable[c] == 1) continue;
                    board[i][j] = c + '0';
                    if (find(board, i, j)) return true;
                }
                board[i][j] = '.';
            }
            y = 0;
        }
        return result;
    }
    
    vector<char> findUsable(matrix &board, int x, int y) {
        vector<char> set(10, 0);
        for (auto i = 0; i < board.size(); ++i) {
            char c = board[i][y];
            if (isNumber(c))
                set[c - '0'] = 1;
        }
        for (auto i = 0; i < board[0].size(); ++i) {
            char c = board[i][y];
            if (isNumber(c))
                set[c - '0'] = 1;
        }
        int b = (x / 3) * 3, c = (y / 3) * 3;
        for (auto i = 0; i < 3; ++i) {
            for (auto j = 0; j < 3; ++j) {
                char d = board[i][y];
                if (isNumber(d))
                    set[d - '0'] = 1;
            }
        }
        
        return set;
    }
    
    bool isNumber(char c) {
        return '0' <= c && c <= '9';
    }
};

