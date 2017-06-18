# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        return self.depth(root)
        
    def depth(self, root):
        if root.left == None and root.right == None:
            return 1
        if root.left == None:
            return self.depth(root.right) + 1
        if root.right == None:
            return self.depth(root.left) + 1
        return min(self.depth(root.left), self.depth(root.right)) + 1
