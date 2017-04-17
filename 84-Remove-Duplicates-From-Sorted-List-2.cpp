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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode node(1);
        node.next = NULL;
        ListNode *last = &node, *next = head;
        while (next != NULL) {
            ListNode *tmp = next;
            while (next != NULL && next->val == tmp->val) next = next->next;
            if (tmp->next == next) {
                last->next = tmp;
                last = last->next;
            }
            else
                last->next = NULL;
        }
        return node.next;
    }
};
