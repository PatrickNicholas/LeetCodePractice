# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.stack = []
        self.res = []
        self.hasPathSum(root, sum)
        return self.res
        
    def hasPathSum(self, root, sum):
        if not root:
            return False

        self.stack.append(root.val)
        if not root.left and not root.right and root.val == sum:
            self.res.append(self.stack[:])
        else:
            sum -= root.val
            self.hasPathSum(root.left, sum)
            self.hasPathSum(root.right, sum)
        self.stack.pop()
