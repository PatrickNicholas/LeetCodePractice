# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0:
            return None
        
        index = inorder.index(postorder[-1])
        node = TreeNode(postorder[-1])
        node.left = self.buildTree(inorder[0:index], postorder[0:index])
        if index >= len(inorder)+1:
            return node
        node.right = self.buildTree(inorder[index+1:], postorder[index:-1])
        return node
