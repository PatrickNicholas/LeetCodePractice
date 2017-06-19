/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    public TreeLinkNode findFirst(TreeLinkNode node) {
        while (node != null) {
            if (node.left != null)
                return node.left;
            else if (node.right != null)
                return node.right;
        }
        return null;
    }
    
    public void connect(TreeLinkNode root) {
        if (root == null)
            return;
        
        TreeLinkNode node = root;
        while (node != null) {
            TreeLinkNode left = node.left, right = node.right;
            if (left != null && right != null) {
                left.next = right;
            } else if (right == null) {
                left.next = findFirst(node.next);
            } else if (left == null) {
                right.next = findFirst(node.next);
            }
            node = node.next;
        }
        connect(findFirst(root));
    }
}
