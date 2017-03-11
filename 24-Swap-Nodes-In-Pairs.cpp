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
    ListNode* swapPairs(ListNode* head) {
        return swap(head);
    } 
    
    ListNode *swap(ListNode *node) {
        if (node == NULL || node->next == NULL)
            return node;
        
        ListNode *tmp = node->next;
        node->next = swap(tmp->next);
        tmp->next = node;
        return tmp;
    }
};
