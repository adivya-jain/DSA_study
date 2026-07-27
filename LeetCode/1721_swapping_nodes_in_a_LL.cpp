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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        ListNode* temp2 = NULL;
        while(temp)
        {
            if(++cnt == k)
            {
                temp2 = temp;
            }
            temp = temp->next;
            
        }

        int kfromlast = cnt - k;
        temp = head;
        while(kfromlast)
        {
            temp = temp->next;
            kfromlast--;
        }

        int var = temp->val;
        temp->val = temp2->val;
        temp2->val = var;

        return head;



    }
};


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
    ListNode* swapNodes(ListNode* head, int k) {
    ListNode* temp = head;
    while(--k)
    {
        temp=temp->next;
    }
    ListNode* temp3 = temp;

    ListNode* temp2 = head;
    while(temp->next)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

    swap(temp3->val,temp2->val);
    return head;
    }
};