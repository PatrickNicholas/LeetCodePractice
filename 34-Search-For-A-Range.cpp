class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto beg = std::lower_bound(nums.begin(), nums.end(), target);
        auto end = std::upper_bound(nums.begin(), nums.end(), target);
        if (end <= beg) return {-1, -1};
        return {beg - nums.begin(), end-nums.begin()-1};
    }
};
