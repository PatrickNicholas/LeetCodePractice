class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.cache = [-1] * (n + 1)
        
        return self.find(n)
    
    def find(self, n):
        if n == 0:
            return 1
        if self.cache[n] != -1:
            return self.cache[n]
        
        sum = 0
        for x in range(0, n):
            sum = sum + self.find(x) * self.find(n-1 - x)
        self.cache[n] = sum
        return sum
