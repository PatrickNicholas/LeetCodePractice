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
    public int sum = 0;
    
    public int sumNumbers(TreeNode root) {
        if (root == null) 
            return 0;
        visit(root, 0);
        return sum;
    }
    
    public void visit(TreeNode node, int sum) {
        sum += node.val;
        if (isLeaf(node)) {
            this.sum += sum;
        }
        
        if (node.left != null)
            visit(node.left, sum * 10);
        
        if (node.right != null) 
            visit(node.right, sum * 10);
    }
    
    public boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }
}
