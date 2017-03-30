class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();
        if (N == 0) return 0;
        vector<vector<int>> map(M, vector<int>(N, INT_MAX));
        map[M-1][N-1] = 0;
        for (int i = N-2; i >= 0; --i) map[M-1][i] = map[M-1][i+1] + grid[M-1][i+1];
        for (int j = M-2; j >= 0; --j) map[j][N-1] = map[j+1][N-1] + grid[j+1][N-1];
        for (int i = M-2; i >= 0; --i) 
            for (int j = N-2; j >= 0; --j) 
                map[i][j] = min(map[i+1][j]+grid[i+1][j], map[i][j+1]+grid[i][j+1]);
        return grid[0][0] + map[0][0];
    }
};
