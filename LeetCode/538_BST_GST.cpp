/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    void sumtree(TreeNode* root, int& sum) {
        if (root == NULL) {
            return;
        }
        // if(root->left == NULL && root->right == NULL)
        // {
        //     return root;
        // }
        sumtree(root->right, sum);

        sum += root->val;
        root->val = sum;
        sumtree(root->left, sum);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        sumtree(root, sum);
        return root;
    }
};