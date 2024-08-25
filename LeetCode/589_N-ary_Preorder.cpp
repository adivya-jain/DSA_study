/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void solve(Node*root,vector<int>&ans)
    {
        if(root == NULL) return;
        //root left right
        ans.push_back(root->val);
        int i=0;
        while( i < root->children.size())
        {
            Node* child = root->children[i];
            solve(child,ans);
            i++;
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};