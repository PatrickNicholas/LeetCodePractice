use std::cmp::Ordering;

impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        if nums.len() < 2 {
            return
        }
        
        let mut idx = nums.len() - 2;
        while idx >= 0 {
            if nums[idx] < nums[idx+1] {
                break;
            } else if idx == 0 {
                nums.sort();
                return
            } else {
                idx = idx - 1;
            }
        }
        let v = nums[idx];
        let swap_idx = idx + 1 + match nums[idx+1..].binary_search_by(|a| a.cmp(&(v+1)).reverse()) {
            Ok(i) => i,
            Err(i) => i - 1,
        };
        nums.swap(swap_idx, idx);
        let unordered = &mut nums[idx+1..];
        unordered.sort()
    }
}