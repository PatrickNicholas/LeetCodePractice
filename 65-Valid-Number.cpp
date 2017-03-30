class Solution {
public:
    bool isNumber(string s) {
        s = trim(s);
        if (s.empty()) return false;
        return parse(s);
    }
    
    bool parse(string &s) {
        int idx = 0;
        if (!parseFloat(s, idx)) return false;
        if (idx >= s.size()) return true;
        if (s[idx] == 'e') {
            idx++;
            if (idx >= s.size()) return false;
            if (!parseInt(s, idx)) return false;
        }
        return idx >= s.size();
    }
    
    bool parseFloat(string &s, int &idx) {
        if (idx >= s.size()) return false;
        if (s[idx] == '-' || s[idx] == '+') idx++;
        if (idx >= s.size()) return false;
        if (s[idx] == '.') return parseNumeric(s, ++idx);
        if (!parseNumeric(s, idx)) return false;
        if (idx >= s.size()) return true;
        if (s[idx] == '.') parseNumeric(s, ++idx);
        return true;
    }
    
    bool parseInt(string &s, int &idx) {
        if (idx >= s.size()) return false;
        if (s[idx] == '-' || s[idx] == '+') idx++;
        if (idx >= s.size()) return false;
        return parseNumeric(s, idx);
    }
    
    bool parseNumeric(string &s, int &idx) {
        int i = idx;
        while (idx < s.size() && isnumeric(s[idx])) idx++;
        return idx != i;
    }
    
    bool isnumeric(char c) {
        return '0' <= c && c <= '9';
    }
    
    string& trim(string &s) {  
        if (s.empty()) 
            return s;  
        s.erase(0, s.find_first_not_of(" "));  
        s.erase(s.find_last_not_of(" ") + 1);  
        return s;  
    }
};
