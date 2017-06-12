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
    ListNode* partition(ListNode* head, int x) {
        ListNode first(0), *p = &first, header(0);
        header.next = head;
        first.next = head;
        
        while (true) {
            ListNode *tmp = &header;
            ListNode *minNode = NULL;
            while (tmp->next != NULL) {
                if (tmp->next->val < x) {
                    minNode = tmp;
                    break;
                }
                tmp = tmp->next;
            }
            
            if (minNode == NULL)
                break;
            
            p->next = minNode->next;
            p = p->next;
            minNode->next = p->next;
            p->next = header.next;
        }
        return first.next;
    }
};
