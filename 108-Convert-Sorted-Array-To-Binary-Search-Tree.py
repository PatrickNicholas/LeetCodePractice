# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        return self.find(nums, 0, len(nums))
        
    def find(self, nums, l, r):
        if l >= r:
            return None
        
        else:
            mid = r - (r-l)/2 - 1
            node = TreeNode(nums[mid])
            node.left = self.find(nums, l, mid)
            node.right = self.find(nums, mid+1, r)
            return node
