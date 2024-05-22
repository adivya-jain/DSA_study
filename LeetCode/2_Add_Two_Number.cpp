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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        int ans = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int a = (temp1 != nullptr) ? temp1->val : 0;
            int b = (temp2 != nullptr) ? temp2->val : 0;

            int sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            if (head == nullptr) {
                head = newNode;
            } else {

                tail->next = newNode;
            }
            tail = newNode;
            if (temp1 != nullptr)
                temp1 = temp1->next;
            if (temp2 != nullptr)
                temp2 = temp2->next;
        }

        return head;
    }
};