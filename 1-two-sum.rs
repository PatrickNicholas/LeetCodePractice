use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut set = HashMap::new();
        for (i, &ele) in nums.iter().enumerate() {
            let left = target - ele;
            if set.contains_key(&left) {
                return vec![set[&left], i as i32];
            }
            set.insert(ele, i as i32);
        }
        unreachable!();
    }
}
