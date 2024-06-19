// APPROACH 1 : LEVEL ORDER TRAVERSAL
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> leftView(Node *root)
{
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

            if(topNode.find(lvl) == topNode.end())
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

// APPROACH 2 : RECURSION

void solve(Node* root,vector<int> &ans,int lvl)
{
    if(root==NULL) return;
    
    if(lvl == ans.size())
    {
        ans.push_back(root->data);
    }
    
    if(root->left)  solve(root->left,ans,lvl+1);
    if(root->right)  solve(root->right,ans,lvl+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
  
    vector<int> ans;
    
    solve(root,ans,0);
    
    return ans;
}