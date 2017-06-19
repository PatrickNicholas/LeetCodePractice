class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
            
        result = []
        trangle = [0] * (numRows+2)
        trangle[0] = 1
        result.append(trangle[0:1])
        
        i = 1
        while i < numRows:
            j = i
            while j > 0:
                trangle[j] = trangle[j] + trangle[j-1]
                j = j - 1
            result.append(trangle[0:i+1])
            i = i + 1
        return result
        
