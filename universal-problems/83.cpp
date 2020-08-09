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
        if (head == nullptr) return head;
        ListNode *p = head -> next;
        ListNode *lst = head;
        while(p != nullptr) {
            if (p -> val != lst -> val) {
                lst -> next = p;
                lst = p;
            }
            p = p -> next;
        }
        lst -> next = nullptr;
        return head;
    }
};
