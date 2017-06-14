# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        if root.left == None and root.right == None:
            return True
        if root.left == None and root.right != None or root.left != None and root.right == None:
            return False
        return self.check(root.left, root.right)
        
    def check(self, lhs, rhs):
        if lhs == None and rhs == None:
            return True
        if lhs == None and rhs != None or lhs != None and rhs == None:
            return False
            
        return lhs.val == rhs.val and self.check(lhs.left, rhs.right) and self.check(lhs.right, rhs.left)
