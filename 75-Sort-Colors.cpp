class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = { 0 };
        for (int i = 0; i < nums.size(); ++i) count[nums[i]]++;
        int idx = 0;
        for (int i = 0; i < 3; ++i) 
            while (count[i]--) nums[idx++] = i;
    }
};
