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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int n = 1;
        ListNode *p = head, *end = NULL;
        while (p->next != NULL) p = p->next, end = p, n++;
        k = k % n;
        if (k == 0 || n == 1) return head;
        
        int j = 1;
        p = head;
        while (j++ < n-k) {
            p = p->next;
        }
        end->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
