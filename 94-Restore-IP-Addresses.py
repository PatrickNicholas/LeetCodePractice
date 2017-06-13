class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        self.result = []
        self.ip = []
        self.find(s, 0, 3)
        return self.result
        
    def join(self):
        self.result.append('.'.join(self.ip))
    
    def find(self, s, index, i):
        if i < 0:
            if index == len(s):
                self.join()
            return
        
        if len(s) - index <= i:
            return 
        
        val = int(s[index])
        self.ip.append(str(val))
        self.find(s, index+1, i-1)
        self.ip.pop()
        
        if val == 0:
            return
        
        if len(s) - index >= 3:
            val = int(s[index:index+3])
            if val < 256:
                self.ip.append(str(val))
                self.find(s, index+3, i-1)
                self.ip.pop()
                
        if (len(s) - index >= 2):
            val = int(s[index:index+2])
            self.ip.append(str(val))
            self.find(s, index+2, i-1)
            self.ip.pop()
            
        
