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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        vector<int> st;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> nextgret(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (st.size() != 0 && st.back() <= nums[i]) {
                st.pop_back();
            }
            if (st.size() != 0) {
                nextgret[i] = st.back();
            }
            st.push_back(nums[i]);
        }

        return nextgret;
    }
};


// using one iteration
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> nums;
        vector<int> st;

        while (head != NULL) {

            int curr = head->val;

            nums.push_back(curr);

            while (!st.empty() && nums[st.back()] < curr) {
                nums[st.back()] = curr;
                st.pop_back();
            }

            st.push_back(nums.size() - 1);

            head = head->next;
        }

        for (int idx : st) {
            nums[idx] = 0;
        }

        return nums;
    }
};