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
    int depthx = 0;
    int depthy = 0;
    TreeNode* px = new TreeNode(0);
    TreeNode* py = new TreeNode(0);
    void check(TreeNode* root, int x, int y, int depth, TreeNode* father) {
        if (root == NULL)
            return;
        if (root->val == x) {
            depthx = depth;
            px = father;
        }
        if (root->val == y) {
            depthy = depth;
            py = father;
        }

        check(root->left, x, y, depth + 1, root);
        check(root->right, x, y, depth + 1, root);
    }
    bool isCousins(TreeNode* root, int x, int y) {

        int depth = 0;
        check(root, x, y, depth, NULL);
        if (depthx == depthy && px != py) {
            return true;
        }
        return false;
    }
};