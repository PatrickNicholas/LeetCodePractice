class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
            
        int val = 0, m = x;
        while (x) {
            val *= 10;
            val += x % 10;
            x /= 10;
        }
        return m == val;
    }
};