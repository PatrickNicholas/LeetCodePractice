```
// manacher
//
class Solution {
public:
    string longestPalindrome(string s) {
        char str[10000] = "";
        int length = initialize(str, s);
        
        int pos = 0, right = 0;
        int pl[10000] = {0};
        
        pl[0] = 1;
        for (int i = 1; i < length; ++i) {
            if (i > right) {
                pl[i] = 1;
            }
            else {
                int j = 2 * pos - i;
                if (j - pl[j] + 1 >= 2 * pos - right && j - pl[j] + 1 <= pos) {
                    pl[i] = pl[j];
                }
                else {
                    pl[i] = right - i + 1;
                }
            }
            
            for (int j = pl[i]; i - j >= 0 && i + j < length; ++j) {
                if (str[i - j] != str[i + j]) 
                    break;
                pl[i]++;
            }
            
            if (pl[i] - 1 + i > right) {
                right = pl[i] - 1 + i;
                pos = i;
            }
        }
        
        int max_ = 0, val = 0;
        for (int i = 0; i < length; ++i) {
            if (pl[i] > max_) {
                max_ = pl[i];
                val = i;
            }
        }
        
        char result[10000];
        int len = 0;
        for (int i = -max_ + 1; i < max_; ++i) {
            if (str[val+i] == '#')
                continue;
            result[len++] = str[val+i];
        }
        result[len++] = 0;
        return result;
    }
    
    int initialize(char *str, string &s) {
        char *p = str;
        *p = '#';
        for (size_t i = 0; i < s.size(); ++i) {
            *p++ = s[i];
            *p++ = '#';
        }
        *p = '\0';
        return p - str;
    }
};
```