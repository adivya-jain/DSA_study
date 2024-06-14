#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left child of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right child of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter the root node" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the left children of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter the right children of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    // creating a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    buildFromLevelOrder(root);
    cout << "Level order traversal of the tree is:" << endl;
    levelOrderTraversal(root);
    // root = buildTree(root);
    /*
    cout << "Level order traversal of the tree is:"<<endl;
    levelOrderTraversal(root);
    cout << "Inorder traversal of the tree is:"<<endl;
    inorder(root);
    cout <<endl<< "Preorder traversal of the tree is:"<<endl;
    preorder(root);
    cout <<endl<< "Postorder traversal of the tree is:"<<endl;
    postorder(root);
    */
    return 0;
}