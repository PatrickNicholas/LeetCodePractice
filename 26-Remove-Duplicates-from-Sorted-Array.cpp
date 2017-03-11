class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[count++] = nums[i];
            while (i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
        return count;
    }
};
