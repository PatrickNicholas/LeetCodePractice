class Solution {
public:
    typedef pair<int, int> point;
    typedef multimap<char, point> char2point;
    typedef pair<char2point::iterator, char2point::iterator> range;
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) 
            return false;
        
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        
        char2point maps;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                maps.insert(make_pair(board[i][j], make_pair(i, j)));
            }
        }
        
        if (word.empty()) 
            return false;
        char a = word[0];
        range r = maps.equal_range(a);
        for (char2point::iterator i = r.first; i != r.second; i++) {
            int x = i->second.first, y = i->second.second;
            visited[x][y] = 1;
            if (find(board, visited, x, y, word.data() + 1)) 
                return true;
            visited[x][y] = 0;
        }
        return false;
    }
    
    bool find(vector<vector<char>> &board, vector<vector<int>> &visited, int x, int y, const char *chars) {
        if (*chars == '\0')
            return true;
        
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
    
        for (int i = 0; i < 4; ++i) {
            if (!can(board, visited, dx[i]+x, dy[i]+y) || board[dx[i]+x][dy[i]+y] != *chars) 
                continue;
            visited[dx[i]+x][dy[i]+y] = 1;
            if (find(board, visited, dx[i]+x, dy[i]+y, chars+1))
                return true;
            visited[dx[i]+x][dy[i]+y] = 0;
        }
        return false;
    }
    
    bool can(vector<vector<char>> &board, vector<vector<int>> &visited, int x, int y) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !visited[x][y]);
    }
};
