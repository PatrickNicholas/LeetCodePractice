class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.size()+1, 0);
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            int sum = digits[i] + carry;
            result[i+1] = sum % 10;
            carry = sum / 10;
        }
        result[0] = carry;
        if (result[0] == 0) result.erase(result.begin());
        return result;
    }
};
