class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
            
        trangle = [0] * (rowIndex+1)
        trangle[0] = 1
        
        i = 1
        while i <= rowIndex:
            j = i
            while j > 0:
                trangle[j] = trangle[j] + trangle[j-1]
                j = j - 1
            i = i + 1
        return trangle
        
