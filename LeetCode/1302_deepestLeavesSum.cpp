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
    void solve(TreeNode* root,map<int,int> &levelsum,int level)
    {
        if(root == NULL) return;
        levelsum[level]+=root->val;
        solve(root->left,levelsum,level+1);
        solve(root->right,levelsum,level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        map<int,int> levelsum;
        solve(root,levelsum,0);
        int maxlevel = 0;
        int sum = 0;
        for(auto it:levelsum)
        {
            if(it.first >= maxlevel)
                sum = it.second;
        }
        return sum;
    }
};