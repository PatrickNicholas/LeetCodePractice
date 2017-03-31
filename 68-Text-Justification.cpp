class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        auto it = words.begin();
        while (it != words.end()) {
            vector<string> tmp;
            int width = it->size(), count = 0;
            tmp.push_back(*it);
            it++;
            while (it != words.end() && it->size() + width + count + 1 <= maxWidth) {
                tmp.push_back(*it);
                width += it->size();
                count++, it++;
            }
            int left = maxWidth - (width + count);
            string str;
            if (it != words.end()) {
                if (tmp.size() == 1) {
                    str = tmp[0];
                    str.append(left, ' ');
                }   
                else {
                    int total = tmp.size()-1;
                    int spacenum = left / total + 1;
                    left = left % total;
                    for (int i = 0; i < left; ++i) {
                        tmp[i].append(1, ' ');
                    }
                    str = tmp[0];
                    for (int i = 1; i < tmp.size(); ++i) {
                        str.append(spacenum, ' ');
                        str.append(tmp[i]);
                    }
                }
            }
            else {
                str = tmp[0];
                for (int i = 1; i < tmp.size(); ++i) str.append(' ' + tmp[i]);
                if (left>0)  str.append(left, ' ');
            }
            result.push_back(str);
        }
        return result;
    }
};

