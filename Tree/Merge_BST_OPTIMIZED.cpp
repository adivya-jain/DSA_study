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
TreeNode* merge2SortedDLL(TreeNode*head1,TreeNode*head2)
{
    TreeNode* head = NULL;
    TreeNode* tail = NULL;


    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1=head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1=head1->right;
            }
        }
        else{
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2=head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2=head2->right;

            }
        }
    }

    while(head1!=NULL)
    {
        tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1=head1->right;
    }
     while(head2!=NULL)
    {
        tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2=head2->right;
    }

    return head;
}
void convertToSortedDLL(TreeNode*root,TreeNode*&head)
{
    if(root==NULL)
    {
        return;
    }
    convertToSortedDLL(root->right, head);
    root->right = head;
    if(head!=NULL) head->left = root ;
    head = root;
    convertToSortedDLL(root->left, head);
}
int count(TreeNode* head)
{
    int cnt = 0 ;
    while(head!=NULL)
    {
        cnt++;
        head= head->right;
    }
    return cnt;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    TreeNode* head1=NULL;
    convertToSortedDLL(root1,head1);
    if (head1 != NULL) 
        head1->left = NULL;
    TreeNode* head2=NULL;
    convertToSortedDLL(root2,head2);
    if (head2 != NULL) 
        head2->left = NULL;
    TreeNode* head = merge2SortedDLL(head1,head2);
    // int cnt = count(head);
    vector<int> ans;
    while(head!=NULL)
    {
        ans.push_back(head->data);
        head = head->right;
    }
    return ans;
    
}