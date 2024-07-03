/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode* root,vector<int> &in)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
// TreeNode* inorderToBst(int start, int end, vector<int> &in) {
//         if (start > end) {
//             return NULL;
//         }
//         int mid = (start + end) / 2;

//         TreeNode* root = new TreeNode(in[mid]);
//         root->left = inorderToBst(start, mid - 1, in);
//         root->right = inorderToBst(mid + 1, end, in);

//         return root;
//     }

vector<int> mergedArrays(vector<int>& BST1, vector<int>&BST2)
{
    vector<int> merged(BST1.size() + BST2.size());
    int i = 0;
    int j=0;
    int k=0;
    while(i<BST1.size() && j<BST2.size())
    {
        if(BST1[i] < BST2[j])
        {
            merged[k++] = BST1[i++];
        }
        else if(BST2[j] < BST1[i])
        {
            merged[k++] = BST2[j++];
        }
        else{
            merged[k++] = BST1[i++];
            merged[k++] = BST2[j++];
        }
    }

    while(j < BST2.size())
    {
        merged[k++] = BST2[j++]; 
    }
    while(i < BST1.size())
    {
        merged[k++] = BST1[i++]; 
    }
    return merged;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> BST1;
    inorder(root1,BST1);

    vector<int> BST2;
    inorder(root2,BST2);
    
    vector<int> mergedArray = mergedArrays(BST1,BST2);

    
    // TreeNode* finalans = inorderToBst(0,merged.size()-1,merged);

    return mergedArray;
    
}