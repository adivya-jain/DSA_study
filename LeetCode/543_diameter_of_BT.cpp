// leeetcode: 543. Diameter of Binary Tree
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
private:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int ans = max(left, right) + 1;

        return ans;
    }

public:
    pair<int, int> diameterFast(TreeNode* root) {
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;
        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        return diameterFast(root).first;
    }
};