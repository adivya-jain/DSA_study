/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class info{
    public:
    int mini;
    int maxi;
    int size;
    bool isBST;
};
info solve(TreeNode *root,int &ans)
{
    if(root==NULL)
    {
        return {INT_MAX, INT_MIN, 0, true};
    }
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);
    info currnode;
    currnode.maxi = max(root->data,right.maxi);
    currnode.mini = min(root->data,left.mini);
    currnode.size = left.size + right.size + 1;
    if(right.isBST && left.isBST && ((root->data > left.maxi) && (root->data < right.mini)))
    {
        currnode.isBST = true;
    }
    else currnode.isBST = false;
  
    if(currnode.isBST)
    {
        ans = max(ans,currnode.size);
    }

    return currnode;
}
int largestBST(TreeNode *root) {
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}