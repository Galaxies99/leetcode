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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL, *q = NULL, *t = head;
        while(t) {
            p = new ListNode(t -> val);
            p -> next = q;
            q = p;
            t = t -> next;
        }
        return q;
    }
};
