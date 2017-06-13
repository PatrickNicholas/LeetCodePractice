class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.dict = dict()
        newnums = []
        for x in nums:
            if x not in self.dict:
                self.dict[x] = 1  
                newnums.append(x)
            else:
                self.dict[x] = self.dict[x] + 1
        self.result = []
        self.subset = []
        
        self.gen(newnums, len(newnums))
        return self.result
        
    def gen(self, nums, n):
        if n == 0:
            self.result.append(self.subset[:])
            return
        
        value = nums[n-1]
        times = self.dict[value]
        
        self.gen(nums, n-1)
        for index in range(0, times):
            self.subset.append(value)
            self.gen(nums, n-1)
        while times > 0:
            self.subset.pop()
            times = times-1
        
            
