class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp = nums;
        do {
            std::next_permutation(tmp.begin(), tmp.end());
            result.push_back(tmp);
        } while (tmp != nums);
        return result;
    }
};
