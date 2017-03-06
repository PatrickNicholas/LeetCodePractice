class Solution {
public:
    struct Rule {
        bool zeroOrMore;
        char ch;
    };
    
    bool isMatch(string s, string p) {
        return normalRule(parseRexpr(p), s.data());
    }
    
    vector<Rule> parseRexpr(const string &p) {
        vector<Rule> rules;
        const char *s = p.data();
        while (*s != '\0') {
            bool rep = false;
            char c = *s++;
            if (*s == '*') {
                rep = true;
                s++;
            }
            rules.push_back((Rule){rep, c});
        }
        return rules;
    }
    
    bool normalRule(const vector<Rule> &rules, const char *p) {
        if (rules.empty() && *p == '\0')
            return true;
            
        for (vector<Rule>::const_iterator it = rules.begin();
            it != rules.end(); it++) {
            if (it->zeroOrMore) {
                char ch = it->ch;
                return specialRule(vector<Rule>(++it, rules.end()), p, ch);
            }
            else if (*p == '\0' || (it->ch != '.' && it->ch != *p)) {
                return false;
            }
            else {
                p++;
            }
        }
        return *p == '\0';
    }
    
    bool specialRule(vector<Rule> rules, const char *p, char ch) {
        const char *tmp = p;
        while (*tmp == ch || (ch == '.' && *tmp != '\0')) {
            if (normalRule(rules, tmp))
                return true;
            tmp++;
        }
        return normalRule(rules, tmp);
    }
};