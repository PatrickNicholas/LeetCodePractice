class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        
        vector<vector<int>> d(word1.size()+1, vector<int>(word2.size()+1, 0));
        
        for (size_t i = 0; i <= word1.size(); ++i) d[i][0] = i;
        for (size_t i = 0; i <= word2.size(); ++i) d[0][i] = i;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                d[i][j] = d[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                d[i][j] = min(d[i][j], min(d[i][j-1], d[i-1][j]) + 1);
            }
        }
        
        return d[word1.size()][word2.size()];
    }
};
