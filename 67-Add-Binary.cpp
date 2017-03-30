class Solution {
public:
    string addBinary(string sa, string sb) {
        string result;
        int length = min(sa.size(), sb.size());
        int carry = 0;
        for (int i = 0; i < length; ++i) {
            int sum = sa[sa.size()-i-1]-'0' + sb[sb.size()-i-1]-'0' + carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        string &s = (sa.size() >= sb.size()) ? sa : sb;
        for (int i = 0; i < s.size()-length; ++i) {
            int sum = s[s.size()-length-i-1]-'0'+carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        if (carry != 0) result.push_back('0'+carry);
        std::reverse(result.begin(), result.end());
        if (result.empty()) return "0";
        return result;
    }
};
