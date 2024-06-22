//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int findpos(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    Node* solve(int in[],int post[],int &postOrderIndex,int inOrderStart,int inOrderend,int n)
    {
        if(postOrderIndex < 0 || inOrderStart > inOrderend)
        {
            return NULL;
        }
        int element = post[postOrderIndex--];
        Node* root = new Node(element);
        // int pos = findPos(in,element,n);
        int pos  = findpos(in , inOrderStart , inOrderend ,element, n);
        root->right = solve(in , post , postOrderIndex , pos+1 , inOrderend ,n);
        root->left = solve(in , post , postOrderIndex  , inOrderStart , pos-1 ,n);
        
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderIndex = n-1;
            // int inOrderStart = 0 ;
            // int inOrderend = n-1;
        
        Node* ans = solve(in,post,postOrderIndex,0,n-1,n);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends