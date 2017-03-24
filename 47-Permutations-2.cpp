class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp = nums;
        do {
            result.push_back(tmp);
            std::next_permutation(tmp.begin(), tmp.end());
        } while (tmp != nums);
        return result;
    }
};
