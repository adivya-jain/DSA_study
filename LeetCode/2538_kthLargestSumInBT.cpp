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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        map<int, long long> mp;
        int level = 0;
        solve(root, level, mp);
        if (mp.size() < k)
            return -1;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(it->second);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }

    void solve(TreeNode* root, int level, map<int, long long>& mp) {
        if (root == NULL) {
            return;
        }
        mp[level] += root->val;
        solve(root->left, level + 1, mp);
        solve(root->right, level + 1, mp);
    }
};