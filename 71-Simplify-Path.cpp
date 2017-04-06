class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return "";
        if (path[path.size()-1] == '/') path.pop_back();
        
        vector<string> paths = split(path, '/');
        vector<string> simplify;
        simplify.push_back("");
        for (auto &s : paths) {
            if (s == "..") {
                simplify.pop_back();
                if (simplify.empty()) simplify.push_back("");
            }
            else if (s != "." && s != "") simplify.push_back(s);
        }
        
        string result = "";
        for (int i = 0; i < simplify.size() - 1; ++i) {
            result += simplify[i] + "/";
        }
        result += simplify[simplify.size() - 1];
        if (simplify.size() == 1 && simplify[0].empty()) result += "/";
        return result;
    }
    
    vector<string> split(string &path, char c) {
        vector<string> result;
        string::size_type index = path.find_first_of(c), last = 0;
        while (index != string::npos) {
            result.push_back(path.substr(last, index - last));
            last = index + 1;
            index = path.find_first_of(c, last);
        }
        if (index - last > 0) result.push_back(path.substr(last, index-last));
        return result;
    }
};
