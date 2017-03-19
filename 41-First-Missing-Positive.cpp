class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i <= size; ++i) {
            while (true) {
                int cur = nums[i-1];
                if (cur <= 0 || cur > size || cur == i || nums[cur-1] == cur) break;
                std::swap(nums[i-1], nums[cur-1]);
            }
            if (nums[i-1] != i)
                nums[i-1] = 0;
        }
        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                return i+1;
            }
        }
        return size+1;
    }
};
