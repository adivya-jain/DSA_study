//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 : Using level order traversal and map to store top node of each level
// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
        if(root == NULL) return ans;
        map<int ,int> topNode;
        queue<pair<Node*,int>> q;
        
        q.push(make_pair(root,0));
        
        
        while(!q.empty())
        {
            pair<Node* ,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int lvl = temp.second;


                topNode[lvl] = frontNode->data;
                
            if(frontNode->left) q.push(make_pair(frontNode->left,lvl+1));
            if(frontNode->right) q.push(make_pair(frontNode->right,lvl+1));
        }
        
        
        
        for(auto i : topNode)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};

// APPROACH 2 : Using Recursion

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root,vector<int> &ans,int lvl)
{
    if(root==NULL) return;
    
    if(lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    if(root->right)  solve(root->right,ans,lvl+1);
    if(root->left)  solve(root->left,ans,lvl+1);
 
}
//Function to return a list containing elements of left view of the binary tree.
 vector<int> rightView(Node *root)
{
  
    vector<int> ans;
    
    solve(root,ans,0);
    
    return ans;
}
};


