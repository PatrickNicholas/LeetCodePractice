# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        node = ListNode(0)
        node.next = head
        h = node
        i = 0
        while i + 1 < m:
            h = h.next
            i = i + 1
        
        if h.next == None:
            return head
        
        current = None
        tail = h.next
        while i < n:
            tmp = h.next
            h.next = h.next.next
            i = i + 1
            tmp.next = current
            current = tmp
        tail.next = h.next
        h.next = current
        return node.next  
            
            
