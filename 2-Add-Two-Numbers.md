```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL) 
            return l1;
            
        int carry = 0;
        ListNode *node1 = l1, *node2 = l2, *result = l1;
        
        carry += node1->val + node2->val;
        node1->val = node2->val = carry % 10;
        carry /= 10;
        
        while (!(node1->next == NULL && node2->next == NULL && carry == 0)) {

        
            if (node1->next == NULL && node2->next == NULL) {
                node1->next = node2->next = new ListNode(1);
                return result;
            } 
            
            
            if (node1->next != NULL && node2->next == NULL) {
                node1 = node1->next;
                carry += node1->val;
                node1->val = carry % 10;
                result = l1;
            } else if (node2->next != NULL && node1->next == NULL) {
                node2 = node2->next;
                carry += node2->val;
                node2->val = carry % 10;
                result = l2;
            } else {
                node1 = node1->next;
                node2 = node2->next;
                carry += node1->val + node2->val;
                node1->val = node2->val = carry % 10;
            }
            carry /= 10;
        }
        return result;
    }
};
```