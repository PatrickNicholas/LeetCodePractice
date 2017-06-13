class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        self.len = n
        self.result = []
        self.code = [0 for _ in range(0, n)]
        self.gen(n)
        return self.result
        
    def gen(self, n):
        if n == 0:
            self.append()
            return
        
        self.gen(n-1)
        self.code[self.len-n] = 0 if self.code[self.len-n] == 1 else 1
        self.gen(n-1)
        
        
    def append(self):
        num = 0
        for x in self.code:
            num = num * 2
            num = num + x
        self.result.append(num)

