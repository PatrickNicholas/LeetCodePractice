class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        vector<int> right(matrix.size(), 0);
        for (int i = 0; i < matrix.size(); ++i)
            right[i] = matrix[i][matrix[0].size()-1];
        
        auto it = std::lower_bound(right.begin(), right.end(), target);
        if (it == right.end()) return false;
        
        int idx = it - right.begin();
        it = std::lower_bound(matrix[idx].begin(), matrix[idx].end(), target);
        if (it == matrix[idx].end()) return false;
        if (*it != target) return false;
        return true;
    }
};
