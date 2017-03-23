class Solution {
public:
    struct Rule {
        bool zeroOrMore;
        string data;
    };
    
    bool isMatch(string s, string p) {
        vector<Rule> rules = parseRules(p);
        return normalRule(parseRules(p), s.data());
    }
    
    vector<Rule> parseRules(const string &p) {
        vector<Rule> rules;
        const char *s = p.data();
        while (*s != '\0') {
            switch (*s) {
                case '*': {
                    while (*s == '*') s++;
                    rules.push_back({true, ""});
                    break;
                }
                case '?': {
                    s++;
                    rules.push_back({false, ""});
                    break;
                }
                default: {
                    string tmp;
                    while (isalpha(*s)) {
                        tmp.push_back(*s);
                        s++;
                    }
                    rules.push_back({false, tmp});
                    break;
                }
            }
        }
        return rules;
    }
    
    bool normalRule(const vector<Rule> &rules, const char *p) {
        if (rules.empty() && *p == '\0')
            return true;
            
        for (vector<Rule>::const_iterator it = rules.begin();
            it != rules.end(); it++) {
            
            if (it->zeroOrMore) {
                return specialRule(vector<Rule>(++it, rules.end()), p);
            }
            else if (*p == '\0')
                return false;
            else if (it->data.empty()) {
                p++;
            }
            else {
                for (int i = 0; i < it->data.size(); ++i) {
                    if (*p == '\0' || it->data[i] != *p) return false;
                    p++;
                }
            }
        }
        return *p == '\0';
    }
    
    bool specialRule(vector<Rule> rules, const char *p) {
        const char *tmp = p;
        int c = ++count;
        while (*tmp != '\0') {
            if (normalRule(rules, tmp))
                return true;
            if (count != c) return false;
            tmp++;
        }
        return normalRule(rules, tmp);
    }
    
    int count = 0;
};
