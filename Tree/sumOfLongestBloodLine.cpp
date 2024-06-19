
class Solution
{
    void solve(Node* root,int len,int &maxlen,int sum, int &maxSum)
    {
        if(root==NULL)
        {
            if(len>maxlen)
            {
                maxSum = sum;
                maxlen = len;
            }
            else if(len == maxlen){
                maxSum = max(maxSum,sum);
            }
            return;
        }
        sum = sum + root->data;
        solve(root->left,len+1,maxlen,sum,maxSum);
        solve(root->right,len+1,maxlen,sum,maxSum);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxlen = 0;
        int sum = 0 ; 
        int maxSum = 0;
        solve(root,len,maxlen,sum,maxSum);
        
        return maxSum;
    }
};
