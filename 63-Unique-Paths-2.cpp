class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        vector<int> result(obstacleGrid[0].size(), 0);
        result[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            result[0] = obstacleGrid[i][0] == 0 ? result[0] : 0;
            for (int j = 1; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 0) result[j] += result[j-1];
                else result[j] = 0;
            }
        }
        return result[obstacleGrid[0].size()-1];
    }
};
