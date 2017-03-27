class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return vector<vector<int>>();
        vector<vector<int>> map(n, vector<int>(n, 0));
        int x = 0, y = -1;
        for (int i = 1; i <= n*n; ) {
            for (int j = 0; j < 4; ++j) {
                while (true) {
                    if (isValid(x+dx[j], y+dy[j], n, n) && !map[x+dx[j]][y+dy[j]]) {
                        x += dx[j];
                        y += dy[j];
                        map[x][y] = i++;
                    }
                    else 
                        break;
                }
            }
        }
        return map;
    }
    
    int dy[4] = { 1, 0, -1, 0 };
    int dx[4] = { 0, 1, 0, -1 };
    
    bool isValid(int x, int y, int M, int N) {
        return (x >= 0 && x < M && y >= 0 && y < N);
    }
};
