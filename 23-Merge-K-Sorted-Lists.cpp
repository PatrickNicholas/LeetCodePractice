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
    struct cmp {
        bool operator() ( ListNode* const &lhs,  ListNode * const &rhs) const {
            return lhs->val > rhs->val;
        }   
    };
    
    typedef priority_queue<ListNode*, vector<ListNode*>, cmp> pqueue;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        pqueue queue;
        for (auto i : lists) if (i != NULL) queue.push(i); 
        ListNode result(0), *p = &result;
        while (!queue.empty()) {
            ListNode *node = queue.top(); queue.pop();
            p->next = node; p = p->next;
            if (node->next != NULL) queue.push(node->next);
        }
        return result.next;
    }
};

