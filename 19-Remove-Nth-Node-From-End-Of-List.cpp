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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        remove(&head, n);
        return head;
    }
    
    int remove(ListNode **node, int n) {
        if (*node == NULL)
            return 0;
        
        int res = remove(&(*node)->next, n) + 1;
        if (res == n) {
            *node = (*node)->next;
        }
        return res;
    }
};
