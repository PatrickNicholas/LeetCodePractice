# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.first = None
        self.second = None
        self.previous = TreeNode(-sys.maxint - 1)
        
        self.traverse(root)
        
        tmp = self.first.val
        self.first.val = self.second.val
        self.second.val = tmp
        
        
    def traverse(self, root):
        if root == None:
            return
            
        self.traverse(root.left)
        if self.first == None and self.previous.val >= root.val:
            self.first = self.previous
        if self.first != None and self.previous.val >= root.val:
            self.second = root
        self.previous = root
        self.traverse(root.right)
