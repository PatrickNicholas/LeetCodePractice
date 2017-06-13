# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.result = []
        self.visit(root)
        return self.result
        
    def visit(self, node):
        if node == None:
            return
        
        self.visit(node.left)
        self.result.append(node.val)
        self.visit(node.right)

