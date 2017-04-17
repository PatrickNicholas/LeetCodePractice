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
        ListNode *last, *next = head;
        while (next != NULL) {
            last = next;
            while (next != NULL && next->val == last->val) next = next->next;
            last->next = next;
        }
        return head;
    }
};
