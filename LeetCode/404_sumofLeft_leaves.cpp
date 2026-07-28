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
    int recursion(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        if (root->left != nullptr && root->left->left == nullptr &&
            root->left->right == nullptr) {
            sum += root->left->val;
        }
        return sum + recursion(root->left, 0) + recursion(root->right, 0);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) 
    { return recursion(root, 0); }
};