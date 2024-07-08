//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    int nodeCount(struct Node* tree)
    {
        if(tree == NULL) return 0;
        int cnt = nodeCount(tree->left) + nodeCount(tree->right)+1;
        return cnt;
    }
  bool isCBT(struct Node* tree,int i , int nodeCount)
  {
      if(tree == NULL)
      {
          return true;
      }
      
      if(i >= nodeCount)   return false;
      else{
        bool leftans = isCBT(tree->left,2*i+1,nodeCount);
        bool rightans = isCBT(tree->right,2*i+2,nodeCount);
        
        return (leftans&&rightans);
      }
  }
  
bool isMaxHeap(struct Node* tree)
{
    if(tree->left == NULL && tree->right == NULL)
    {
        return true;
    }
    else if(tree->right == NULL)
    {
        return tree->data >= tree->left->data;
    }
    else
    {
        bool left = tree->data >= tree->left->data && isMaxHeap(tree->left);
        bool right = tree->data >= tree->right->data && isMaxHeap(tree->right);
        return left && right;
    }
}
  
public:
bool isHeap(struct Node* tree) {
    int cnt = nodeCount(tree);
    
    if(isCBT(tree, 0, cnt) && isMaxHeap(tree))
    {
        return true;
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends