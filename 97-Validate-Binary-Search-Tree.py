# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.status = True
        if root == None:
            return True
        self.valid(root)
        return self.status
    
    def valid(self, node):
        if node.left == None and node.right == None:
            return (node.val, node.val)
        elif node.left == None:
            l, r = self.valid(node.right)
            if not self.status:
                return (0, 0)
            self.status = self.status and node.val < l
            return (node.val, r)
        elif node.right == None:
            l, r = self.valid(node.left)
            if not self.status:
                return (0, 0)
            self.status = self.status and node.val > r
            return (l, node.val)
        else:
            l1, r1 = self.valid(node.left)
            self.status = self.status and node.val > r1
            l2, r2 = self.valid(node.right)
            self.status = self.status and node.val < l2
            return (l1, r2)
            
