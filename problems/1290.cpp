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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode *p = head;
        while(p) {
            res = (res << 1) + p -> val;
            p = p -> next;
        }
        return res;
    }
};
