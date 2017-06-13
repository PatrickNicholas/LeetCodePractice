class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.str = list(s)
        self.cache = [-1] * len(self.str)
        if len(self.str) == 0:
            return 0 
        return self.find(0)
    
    def find(self, index):
        if index >= len(self.str):
            return 1
        if self.cache[index] != -1:
            return self.cache[index]
        
        times = 0
        if index + 1 < len(self.str):
            a = self.str[index]
            b = self.str[index + 1]
            if (a == '2' and b <= '6') or a < '2':
                times = times + self.find(index + 2)
        if self.str[index] != '0':
            times = times + self.find(index+1)
        else:
            times = 0
        self.cache[index] = times
        return times
        
