// GFG https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root == NULL)
       {
           return NULL;
       }
       if(root->data == n1 || root->data == n2)
       {
           return root;
       }
       
       Node* leftans = lca(root->left,n1,n2);
       Node* rightans = lca(root->right,n1,n2);
       
       //4 cases possible 
       //1st
       if(leftans!=NULL && rightans != NULL)
       {
           return root;
       }
       else if(leftans!=NULL && rightans == NULL)
       {
           return leftans;
       }
       else if(leftans == NULL && rightans!= NULL)
       {
           return rightans;
       }
              else{
           return NULL;
       }
    }
};



