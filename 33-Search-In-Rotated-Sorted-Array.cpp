class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums[0] < target) {
            for (int i = 0; i < nums.size(); ++i) {
                if (target < nums[i]) return -1;
                if (target == nums[i]) return i;
            }
            return -1;
        }
        else if (nums[0] > target) {
            for (int i = nums.size()-1; i > 0; --i) {
                if (nums[i] < target) return -1;
                if (target == nums[i]) return i;
            }
            return -1;
        }   
        else {
            return 0;
        }
    }
};
