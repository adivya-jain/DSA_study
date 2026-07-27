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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt=0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }

        int numofgrpswithextraelements = cnt % k;
        int numofgrpswithgeneralelements = cnt / k;
        vector<int> partsizes(k,numofgrpswithgeneralelements);
        for(int j=0;j<numofgrpswithextraelements;j++)
        {
            partsizes[j]++;
        }

        vector<ListNode*> result;
        temp = head;
        for(int i=0;i<k;i++)
        {
            result.push_back(temp);
            int currpartsize = partsizes[i];
            for(int j=0;j< (currpartsize - 1) && temp!=NULL;j++)
            {
                temp = temp->next;
            }

            if(temp!=NULL)
            {
                ListNode* nextpart = temp->next;
                temp->next  = NULL;
                temp = nextpart;
            }
        }

        return result;


        
    }
};