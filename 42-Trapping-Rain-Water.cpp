class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        std::stack<int> stack;
        int curmax = -1;
        for (int i = height.size()-1; i > 0; --i) {
            if (height[i] >= curmax) {
                curmax = height[i];
                stack.push(i);
            }
        }
        int result = 0;
        for (int i = 0; i < height.size()-1; ++i) {
            int left = i, right = stack.top();
            while (i < right-1 && height[i+1] < height[left]) {
                i++;   
            }
            int h = min(height[i+1], height[left]);
            for (int j = left+1; j < i+1; ++j) {
                result += h - height[j];
            }
            if (i + 1 == right) stack.pop();
        }
        return result;
    }
};
