class Solution {
public:
    typedef vector<int> Array;
    typedef vector<Array> Arrays;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        Arrays result; Array tmp;
        std::sort(candidates.begin(), candidates.end());
        combination(result, tmp, candidates, 0, target);
        return result;
    }
    
    void combination(Arrays &result, Array &tmp, Array &candidates, size_t beg, int target) {
        if (target == 0) {
            result.push_back(tmp);
            return ;
        }

        for (size_t i = beg; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            tmp.push_back(candidates[i]);
            combination(result, tmp, candidates, i, target - candidates[i]);
            tmp.pop_back();
        }
    }
};

