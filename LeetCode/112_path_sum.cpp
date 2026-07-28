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
public:
    bool findSum(TreeNode* root, int currentSum, int targetSum) {
        if (root == NULL)
            return false;

        currentSum += root->val;
        if ((currentSum == targetSum) && root->left == nullptr && root->right == nullptr)
            return true;
        return findSum(root->left, currentSum, targetSum) ||
               findSum(root->right, currentSum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return findSum(root, sum, targetSum);
    }
};