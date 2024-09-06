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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        unordered_set<int> numSet(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++) {
        //     mp[nums[i]] = true;
        // }
        // while (mp.find(head->val) !mp.end()) {
        //     head = head->next;
        // }
        ListNode* curr = head;

        while (curr != NULL) {
            if (numSet.find(curr->val) != numSet.end()) {
                prev->next = curr->next;
                delete curr;
            } else {
                prev = curr;
            }
            curr = prev->next;
        }

        return dummy.next;
    }
};