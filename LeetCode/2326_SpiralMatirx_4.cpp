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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int toprow = 0;
        int bottomrow = m - 1;
        int leftcol = 0;
        int rightcol = n - 1;

        while (head != NULL) {
            // filled top row
            if (head != NULL) {
                for (int i = leftcol; i <= rightcol && head != NULL; i++) {
                    matrix[toprow][i] = head->val;
                    head = head->next;
                }
                toprow++;
            }
            if (head != NULL) {
                // filled right column
                for (int i = toprow; i <= bottomrow && head != NULL; i++) {
                    matrix[i][rightcol] = head->val;
                    head = head->next;
                }
                rightcol--;
            }
            if (head != NULL) {
                // botom row
                for (int i = rightcol; i >= leftcol && head != NULL; i--) {
                    matrix[bottomrow][i] = head->val;
                    head = head->next;
                }
                bottomrow--;
            }
            if (head != NULL) {
                // filled left col
                for (int i = bottomrow; i >= toprow && head != NULL; i--) {
                    matrix[i][leftcol] = head->val;
                    head = head->next;
                }
                leftcol++;
            }
        }
        return matrix;
    }
};