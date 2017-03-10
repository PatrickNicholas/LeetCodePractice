class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            else {
                if (stack.empty() || !equal(stack.top(),c))
                    return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
    
    bool equal(char c, char b) {
        return c == '(' && b == ')' ||
            c == '[' && b == ']' ||
            c == '{' && b == '}';
    }
};
