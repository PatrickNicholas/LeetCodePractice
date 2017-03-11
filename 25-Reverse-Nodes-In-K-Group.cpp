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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        return reverse(head, k);
    }
    
    ListNode *reverse(ListNode *head, int k) {
        vector<ListNode*> nodes;
        nodes.reserve(k);
        ListNode *node = head;
        for (int i = 0; i < k; ++i) {
            if (node == NULL) break;
            nodes.push_back(node);
            node = node->next;
        }
        if (nodes.size() < k) return head;
        ListNode tmp(0), *p = &tmp;
        for (int i = 0; i < k; ++i) {
            p->next = nodes.back(); 
            p = p->next;
            nodes.pop_back();
        }
        p->next = reverse(node, k);
        return tmp.next;
    }
};

