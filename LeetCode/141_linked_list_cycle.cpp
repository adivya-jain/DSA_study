// 141. Linked List Cycle

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
    bool hasCycle(ListNode* head) {
        std:map<ListNode*, bool> visited;
        ListNode* temp = head;

        if (temp==NULL) {
            return false;
        }
         if (temp->next==NULL) {
            return false;
        }

        while (temp != NULL) {
            if (visited[temp]==true)  {
                return true;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};
