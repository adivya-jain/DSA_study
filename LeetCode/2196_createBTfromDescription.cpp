
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
         unordered_map<int, bool> hasParent;
        // vector<bool> visited(100001, false);
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2] == 1;

            if (mp.find(parentVal) == mp.end()) {
                mp[parentVal] = new TreeNode(parentVal);
            }
            if (mp.find(childVal) == mp.end()) {
                mp[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                mp[parentVal]->left = mp[childVal];
            } else {
                mp[parentVal]->right = mp[childVal];
            }

            hasParent[childVal] = true;
        }

        TreeNode* root = nullptr;
        for (const auto& desc : descriptions) {
            if (!hasParent[desc[0]]) {
                root = mp[desc[0]];
                break;
            }
        }

        return root;
    }
};