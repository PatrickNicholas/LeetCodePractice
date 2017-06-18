# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.res = True
        self.depth(root)
        return self.res
        
        
    def depth(self, root):
        if root == None:
            return 0
        
        left = self.depth(root.left)
        right = self.depth(root.right)
        if left > right:
            self.res = self.res and left - right <= 1
        else:
            self.res = self.res and right - left <= 1
        return max(left, right) + 1
    
