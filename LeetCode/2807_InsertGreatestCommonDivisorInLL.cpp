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
    int gcd(int a ,int b)
    {
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = prev->next;

        while(curr!=NULL)
        {
            int tempval = gcd(min(prev->val,curr->val),max(prev->val,curr->val));
            ListNode* temp=new ListNode(tempval);
            // temp->val = tempval;

            temp->next = curr;
            prev->next = temp;
            prev = curr;
            curr=curr->next;

        }
        return head;
    }
};