class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        vector<int> failed = getNext(needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while (j && haystack[i] != needle[j]) j = failed[j];
            if (haystack[i] == needle[j]) j++;
            if (j == needle.size()) return i-j+1;
        }
        return -1;
    }
    
    vector<int> getNext(string &str) {
        vector<int> failed(str.size()+5, 0);
        for (int i = 1; i < str.size(); ++i) {
            int j = failed[i];
            while (j && str[j] != str[i]) j = failed[j];
            failed[i+1] = str[j] == str[i] ? j+1 : 0;
        }
        return failed;
    }
};

