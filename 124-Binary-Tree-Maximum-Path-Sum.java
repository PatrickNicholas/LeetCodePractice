/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        findPath(root);
        return max;
    }
    
    public int findPath(TreeNode root) {
        if (root == null) 
            return 0;
        int left = findPath(root.left);
        int right = findPath(root.right);
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        max = Math.max(max, left + right + root.val);
        return Math.max(left, right) + root.val;
    }
}
