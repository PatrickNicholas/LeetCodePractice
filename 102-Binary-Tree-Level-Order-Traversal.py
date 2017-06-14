# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return [] 
        else:
            self.result = []
            parent = [root]
            self.result.append([root.val])
            while len(parent) != 0:
                result = []
                values = []
                for node in parent:
                    if node.left != None:
                        values.append(node.left.val)
                        result.append(node.left)
                    if node.right != None:
                        values.append(node.right.val)
                        result.append(node.right)
                if len(values) != 0:
                    self.result.append(values)
                parent = result
            return self.result
        
        
