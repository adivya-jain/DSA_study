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
    
public:
int res;
    vector<int> dfs(TreeNode* root,int distance)
    {
        vector<int> numberOfNodes(distance + 1, 0);
        if(root == NULL)
        {
            return numberOfNodes;
        }else if(root->left == NULL && root->right == NULL)
        {           
            numberOfNodes[1]=1;
            return numberOfNodes;
        }
        

        vector<int> leftleafnode = dfs(root->left,distance);
        vector<int> rightleafnode = dfs(root->right,distance);
        for(int i=1;i<=distance;i++)
        {
            for(int j=1;j<=distance;j++)
            {
                if(i+j<=distance)
                {
                    res+=leftleafnode[i] * rightleafnode[j];
                }
            }
        }
        for(int i=1;i<distance;i++)
        {
            numberOfNodes[i] = leftleafnode[i-1] + rightleafnode[i-1];
        }
        return numberOfNodes;
    }
    int countPairs(TreeNode* root, int distance) {
        // int count = 0;
        res = 0;
        vector<int> ansDistance = dfs(root,distance);

        return res;
    }
};