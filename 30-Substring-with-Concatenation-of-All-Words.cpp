class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        unordered_map<string, int> dict;
        for (auto &str : words) {
            dict[str] += 1;
        }
        
        int wordsize = words[0].size(), wordssize = words.size();
        for (int i = 0; i < s.size(); ++i) {
            unordered_map<string, int> maps;
            unordered_map<string, int> firstidx;
            
            int count = 0;
            for (int j = i; j <= s.size() - wordsize; j += wordsize) {
                string str = s.substr(j, wordsize);
                
                // if not exists.
                if (dict.count(str) == 0) {
                    break;
                }
                
                int &total = maps[str];
                // got first...
                if (total == dict[str]) {
                    i = firstidx[str];
                    break;
                }
                
                // take count.
                if (total == 0) firstidx[str] = j;
                total += 1;
                if (++count == wordssize)
                    result.push_back(i);
            }
        }
        return result;
    }
};
