class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        idx = m + n - 1
        l = m - 1
        r = n - 1
        while l >= 0 and r >= 0:
            if nums1[l] >= nums2[r]:
                nums1[idx] = nums1[l]
                l = l - 1
            else:
                nums1[idx] = nums2[r]
                r = r - 1
            idx = idx - 1
        if r >= 0:
            for i in list(range(r+1)):
                nums1[i] = nums2[i]
