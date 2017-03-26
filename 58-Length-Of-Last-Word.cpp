class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (cur > 0)
                    result = cur;
                cur = 0;
            }
            else 
                cur++;
        }
        if (cur > 0)
            result = cur;
        return result;
    }
};
