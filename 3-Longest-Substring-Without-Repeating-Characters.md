```
/* 3 - Longest Substring Without Repeating Characters */
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if (str.size() == 0 || str.size() == 1)
            return str.size();
        
        int left = 0, right = 1;    // [left, right)
        int index[128] = {1}, length = 1;
        
        index[str[left]] = 1;
        while (right < str.size()) {
            char a = str[right];
            
            if (index[a] == 0) {   // without
                index[a] = 1;         // add
            }
            else {
                while (str[left] != a) {
                    index[str[left]] = 0;  // del
                    left++;
                }
                left++;
            }
            
            right++;
            
            int current = right - left;
            if (length < current) 
                length = current;
        }
        return length;
    }
};
```