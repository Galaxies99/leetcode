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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *p = nullptr;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr) {
            if (head == nullptr) {
                head = new ListNode(l1 -> val + l2 -> val + carry, nullptr);
                p = head;
            } else {
                p -> next = new ListNode(l1 -> val + l2 -> val + carry, nullptr);
                p = p -> next;
            }
            carry = (p -> val >= 10);
            if (carry) p -> val -= 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != nullptr) {
            if (head == nullptr) {
                head = new ListNode(l1 -> val + carry, nullptr);
                p = head;
            } else {
                p -> next = new ListNode(l1 -> val + carry, nullptr);
                p = p -> next;
            }
            carry = (p -> val >= 10);
            if (carry) p -> val -= 10;
            l1 = l1 -> next;
        }
        while(l2 != nullptr) {
            if (head == nullptr) {
                head = new ListNode(l2 -> val + carry, nullptr);
                p = head;
            } else {
                p -> next = new ListNode(l2 -> val + carry, nullptr);
                p = p -> next;
            }
            carry = (p -> val >= 10);
            if (carry) p -> val -= 10;
            l2 = l2 -> next;
        }
        if (carry) {
            if (head == nullptr) head = new ListNode(carry, nullptr);
            else p -> next = new ListNode(carry, nullptr);
        }
        return head;
    }
};
