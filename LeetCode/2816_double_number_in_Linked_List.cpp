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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        ListNode* temp = head;
        int carry = 0;

        while (temp) {
            int value = temp->val * 2 + carry;
            temp->val = value % 10;
            carry = value / 10;

            if (temp->next == nullptr && carry) {
                temp->next = new ListNode(0);
            }

            temp = temp->next;
        }

        return reverse(head);
    }
};