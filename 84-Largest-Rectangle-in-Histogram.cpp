class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        int max_ = 0;
        for (auto i : heights) {
            if (stack.empty())
                stack.push(i);
            else {
                int l = stack.top();
                if (l <= i) {
                    stack.push(i);
                }
                else {
                    int count = 1;
                    while (!stack.empty() && stack.top() > i) {
                        int t = stack.top();
                        stack.pop();
                        if (t * count > max_) {
                            max_ = t * count;
                        }
                        count++;
                    }
                    for (int j = 0; j < count; j++) {
                        stack.push(i);
                    }
                }
            }
        }
        if (!stack.empty()) {
            int count = stack.size();
            for (int i = 1; i <= count; ++i) {
                int t = stack.top();
                stack.pop();
                if (t * i > max_)
                    max_ = t * i;
            }
        }
        return max_;
    }
};
