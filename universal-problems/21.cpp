/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prev = nullptr, *head = nullptr;
        while(l1 && l2) {
            if (l1 -> val < l2 -> val) {
                if (prev) prev -> next = l1;
                else head = l1;
                prev = l1;
                l1 = l1 -> next;
            } else {
                if (prev) prev -> next = l2;
                else head = l2;
                prev = l2;
                l2 = l2 -> next;
            }
        }
        if (l1) {
            if (prev) prev -> next = l1;
            else head = l1;
        }
        if (l2) {
            if (prev) prev -> next = l2;
            else head = l2;
        }
        return head;    
    }
};
