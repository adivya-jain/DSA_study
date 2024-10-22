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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return root;
        int prevSum = root->val;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        vector<int> levelSums;
        while (!nodeQueue.empty()) { // 1st pass
             int levelSum = 0;
             int queueSize = nodeQueue.size();
            for (int i = 0; i < queueSize; i++) {
               
                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();
                levelSum += curr->val;
                if (curr->left) {
                    nodeQueue.push(curr->left);
                }
                if (curr->right) {
                    nodeQueue.push(curr->right);
                }
            }
            levelSums.push_back(levelSum);
        }

        nodeQueue.push(root);
        root->val = 0;
        int levelIndex = 1;
        while (!nodeQueue.empty()) {
             int queueSize = nodeQueue.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();
                int sibilingSum = 0;
                if (curr->left)
                    sibilingSum += curr->left->val;
                if (curr->right)
                    sibilingSum += curr->right->val;

                if (curr->left) {
                    curr->left->val = levelSums[levelIndex] - sibilingSum;
                    nodeQueue.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = levelSums[levelIndex] - sibilingSum;
                    nodeQueue.push(curr->right);
                }
            }
            levelIndex++;
        }

        return root;
    }
};