class Solution {
public:
    int myAtoi(string str) {
        string::iterator it = str.begin();
        
        // skip white space
        while (it != str.end() && *it == ' ') {
            it++;
        }
        
        if (it == str.end()) 
            return 0;
        
        // get sign
        bool positive = true;
        if (*it == '+' || *it == '-') {
            if (*it++ == '-') 
                positive = false;
        }
        
        long long int result = 0ll;
        while (it != str.end() && '0' <= *it && *it <= '9') {
            result *= 10ll;
            if (positive) {
                result += *it++ - '0';
            }
            else {
                result -= *it++ - '0';
            }
            
            // when out of range, break
            if (result > 2147483647 || result < -2147483648)
                break;
        }
        
        if (result > 2147483647)
            return 2147483647;
        else if (result < -2147483648)
            return -2147483648;
        else 
            return result;
    }
};