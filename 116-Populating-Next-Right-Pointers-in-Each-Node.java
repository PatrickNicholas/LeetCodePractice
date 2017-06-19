tion for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null) 
            return;
        
        Queue<TreeLinkNode> queue = new Queue<>();
        queue.offer(root);
        connect(queue);
    }
    
    public void offer(Queue<TreeLinkNode> queue, TreeLinkNode node) {
        if (node.left != null)
            queue.offer(node.left);
        if (node.right != null) 
            queue.offer(node.right)
    }
    
    public void connect(Queue<TreeLinkNode> queue) {
        while (!queue.isEmpty()) {
            TreeLinkNode node = queue.poll();
            Queue<TreeLinkNode> childs = new Queue<TreeLinkNode>();
            offer(childs, node);
            while (!queue.isEmpty()) {
                node.next = queue.poll();
                node = node.next;
                offer(childs, node);
            }
            queue = childs;
        }
    }
}
