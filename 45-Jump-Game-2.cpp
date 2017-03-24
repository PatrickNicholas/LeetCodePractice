class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        vector<int> result(nums.size(), INT_MAX);
        result[0] = 0;
        int count = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = count - i; j <= nums[i]; ++j) {
                if (i + j >= nums.size()) break;
                count ++;
                result[i+j] = min(result[i] + 1, result[i+j]);
            }
            if (count > nums.size()) break;
        }
        return result[nums.size()-1];
    }
};
