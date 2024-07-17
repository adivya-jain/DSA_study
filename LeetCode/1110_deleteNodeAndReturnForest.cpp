class Solution {

    TreeNode* solve(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& ans) {
        if (root == NULL) {
            return NULL;
        }
        root->left = solve(root->left,to_delete,ans);
        root->right = solve(root->right,to_delete,ans);
        int value = root->val;

         if (std::find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end())
        {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
            return root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        if (std::find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) {
            ans.push_back(root);  // Add root only if it's not in to_delete
        }
        solve(root, to_delete, ans);
        return ans;
    }
};