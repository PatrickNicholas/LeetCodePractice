class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res = max(sum, res);
            if (sum < 0) {
                sum = 0;
                continue;
            }
        }
        return res;
    }
};
