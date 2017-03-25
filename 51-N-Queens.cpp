class Solution {
public:
    bool check(vector<int> &queens, int x, int y) {
        for (int j = 0; j < queens.size(); ++j) {
            if (queens[j] == -1) break;
            if (y == queens[j] || abs(x - j) == abs(y - queens[j]))
                return false;
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n, -1);
        solve(queens, n, 0);
        return result;
    }
    
    void solve(vector<int> &queens, int n, int x) {
        if (x == n) {
            addresult(queens, n);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (!check(queens, x, i)) continue;
            queens[x] = i;
            solve(queens, n, x + 1);
            queens[x] = -1;
        }
    }
    
    void addresult(vector<int> &queens, int n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][queens[i]] = 'Q';
        }
        result.push_back(board);
    }
    
    vector<vector<string>> result;
};
