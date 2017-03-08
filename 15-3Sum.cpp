class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> resultSet;
        if (nums.size() < 3)
            return resultSet;
        
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i <= length - 3; ++i) {
            int j = length - 1, k = i + 1;
            while (k < j) {
                int sum = nums[k] + nums[j] + nums[i];
                if (sum == 0) {
                    resultSet.push_back({nums[i], nums[k], nums[j]});
                    k++, j--;
                    while (k < j && nums[k] == nums[k-1]) k++;
                    while (k < j && nums[j] == nums[j+1]) j--;
                }
                else if (sum > 0) {
                    j--;
                }
                else {
                    k++;
                }
            }
            while (i <= length - 3 && nums[i] == nums[i+1]) ++i;
        }
        return resultSet;
    }
};
