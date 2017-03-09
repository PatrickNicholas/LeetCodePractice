class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int closet = target - (nums[0] + nums[1] + nums[2]);
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i <= length - 3; ++i) {
            int j = length - 1, k = i + 1;
            while (k < j) {
                int sum = nums[k] + nums[j] + nums[i];
                if (sum == target) return target;
                if (abs(closet) > abs(target - sum)) closet = target - sum;
                if (sum > target) j--; else k++;
            }
            while (i <= length - 3 && nums[i] == nums[i+1]) ++i;
        }
        return target - closet;
    }
};

