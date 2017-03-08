class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1) 
            return "";
        if (strs.size() < 2)
            return strs[0];
        
        std::sort(strs.begin(), strs.end());
        string &a = strs[0];
        string &b = strs.back();
        
        int idx = 0;
        for (auto c : a) {
            if (idx > b.size() || b[idx] != c) {
                break;
            }
            idx++;
        }
        return b.substr(0, idx);
    }
};
