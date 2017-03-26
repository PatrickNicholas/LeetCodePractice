class Solution {
public:
    int dy[4] = { 1, 0, -1, 0 };
    int dx[4] = { 0, 1, 0, -1 };
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0) return vector<int>();
        int N = matrix[0].size();
        
        vector<vector<int>> visited(M, vector<int>(N, 0));
        vector<int> result;
        int x = 0, y = -1;
        while (result.size() != M * N) {
            for (int i = 0; i < 4; ++i) {
                while (true) {
                    if (isValid(x+dx[i], y+dy[i], M, N) && !visited[x+dx[i]][y+dy[i]]) {
                        x += dx[i];
                        y += dy[i];
                        result.push_back(matrix[x][y]);
                        visited[x][y] = 1;
                    }
                    else 
                        break;
                }
            }
        }
        return result;
    }
    
    bool isValid(int x, int y, int M, int N) {
        return (x >= 0 && x < M && y >= 0 && y < N);
    }
};
