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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head;
        while(p) {
            ++ n;
            p = p -> next;
        }
        k = n - k;
        p = head;
        while(k --) 
            p = p -> next;
        return p;
    }
};
