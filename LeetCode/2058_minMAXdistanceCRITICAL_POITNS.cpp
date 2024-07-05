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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalIndex;
        int mini = INT_MAX;
        int criticalCount = 1;
        ListNode* prev = head;
        ListNode* temp = head->next;
        while (temp != NULL) {
            if (temp->next != NULL) {
                if (prev->val > temp->val) {
                    if (temp->val < temp->next->val) {
                        criticalIndex.push_back(criticalCount);
                    }
                } else if (prev->val < temp->val) {
                    if (temp->val > temp->next->val) {
                        criticalIndex.push_back(criticalCount);
                    }
                }
            }
            prev=temp;
            temp = temp->next;
        
            criticalCount = criticalCount + 1;
        }
        if (criticalIndex.size() < 2) {
            mini = -1;
            maxi = -1;
        } else {
            for (int i = 1; i < criticalIndex.size(); i++) {
                mini = min(mini, criticalIndex[i] - criticalIndex[i - 1]);
            }
            maxi = max(maxi, criticalIndex[criticalIndex.size() - 1] -
                                 criticalIndex[0]);
        }

        return {mini,maxi};
    }
};