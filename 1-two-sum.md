```
/* Two Sum - https://leetcode.com/problems/two-sum/?tab=Description */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, sum;  
        vector<int> results;  
        map<int, int> hmap;  
        for(i=0; i<nums.size(); i++){  
            if(!hmap.count(nums[i])){  
                hmap.insert(pair<int, int>(nums[i], i));  
            }  
            if(hmap.count(target-nums[i])){  
                int n=hmap[target-nums[i]];  
                if(n<i){  
                    results.push_back(n+1);  
                    results.push_back(i+1);  
                    return results;  
                }  
  
            }  
        }  
        return results;  
    }
};
```