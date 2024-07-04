
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int currsum = 0;
        ListNode* ans = head;
        ListNode* temp = head;
        temp=temp->next;
        while(temp!=NULL)
        {
            currsum = currsum + temp->val;

            if(temp->val == 0)
            {
                ListNode* newNode = new ListNode(currsum);
                head->next = newNode;
                head=head->next;
                currsum=0;
            }
            temp = temp->next;
        }

        return ans->next;
    }
};