class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, count = 0;
        while (idx < nums.size()) {
            int last = nums[idx], beg = idx;
            while (idx < nums.size() && nums[++idx] == last);
            int size = (idx - beg) < 2 ? 1 : 2;
            for (int i = count; i < count + size; ++i) {
                nums[i] = last;
            }
            count += size;
        }
        return count;
    }
};
