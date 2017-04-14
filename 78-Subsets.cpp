class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> values;
        values.reserve(nums.size());
        find(result, nums, values, 0);
        return result;
    }
    
    void find(vector<vector<int>> &result, vector<int> & nums, vector<int> &values, int at) {
        if (at >= nums.size()) {
            result.push_back(values);
            return;
        }
        
        find(result, nums, values, at+1);
        values.push_back(nums[at]);
        find(result, nums, values, at+1);
        values.pop_back();
    }
};
