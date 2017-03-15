class Solution {
public:
    typedef vector<vector<char>> matrix;
    void solveSudoku(vector<vector<char>>& board) {
        find(board, 0, 0);
    }

    bool find(matrix &board, int x, int y) {
        for (int i = x; i < 9; ++i) {
            for (int j = y; j < 9; ++j) {
                if (board[i][j] != '.') continue;
                return tryFill(board, i, j);
            }
            y = 0;
        }
        return true;
    }
    
    bool tryFill(matrix &board, int i, int j) {
        vector<char> used = findUsed(board, i, j);
        for (int c = 1; c < 10; ++c) {
            if (used[c]) continue;
            board[i][j] = c + '0';
            if (find(board, i, j+1)) return true;
        }
        board[i][j] = '.';
        return false;
    }
    
    vector<char> findUsed(matrix &board, int x, int y) {
        vector<char> set(10, 0);
        for (auto i = 0; i < 9; ++i) {
            char c = board[x][i];
            if (c != '.') set[c - '0'] = 1;
        }
        
        for (auto i = 0; i < 9; ++i) {
            char c = board[i][y];
            if (c != '.') set[c - '0'] = 1;
        }
        
        int b = (x / 3) * 3, c = (y / 3) * 3;
        for (auto i = 0; i < 3; ++i) {
            for (auto j = 0; j < 3; ++j) {
                char d = board[b+i][c+j];
                if (d != '.') set[d - '0'] = 1;
            }
        }
        
        return set;
    }
};