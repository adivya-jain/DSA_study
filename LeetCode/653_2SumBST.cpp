/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void solve(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        solve(root,ans);

        int start = 0 ; 
        int end = ans.size() - 1;

        while(start<end)
        {
            int res = ans[start] + ans[end];
            if( res == k)
            {
                return true;
            }
            else if(res > k )
            {
                end--;
            }
            else{
                start++;
            }
        } 
        return false;
    }
};