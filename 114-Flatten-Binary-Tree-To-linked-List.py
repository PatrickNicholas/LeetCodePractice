# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.head = TreeNode(1)
        self.last = self.head
        self.flat(root)
        
    def flat(self, root):
        if not root:
            return 
        
        left = root.left
        right = root.right
        root.left = None
        root.right = None
        self.last.right = root
        self.last = root
        
        print(root.val)
        
        self.flat(left)
        self.flat(right)
        
