class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        int length = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < length-3; ++i) {
            for (int j = i + 1; j < length-2; ++j) {
                int l = j + 1, r = length-1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target && l != j && r != j) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;
                        while (nums[l] == nums[l-1] && l < r) l++;
                        while (nums[r] == nums[r+1] && l < r) r--;
                    }
                    else if (sum > target) {
                        r--;
                    }
                    else {
                        l++;
                    }
                }
                while (j < length-2 && nums[j] == nums[j+1]) j++;
            }   
            while (i < length-3 && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};

