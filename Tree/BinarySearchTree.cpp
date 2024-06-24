#include<iostream>
#include <queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertElement(Node* root,int data)
{
    if(root==NULL)
    {
        Node* newNode = new Node(data);
        return newNode;
    }

    if(data<root->data)
    {
        root->left = insertElement(root->left,data);
    }
    else
    {
        root->right = insertElement(root->right,data);
    }

    return root;
}
void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root = insertElement(root,data);
        cin >> data;
    }
}
void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node* root = NULL;
    cout<<"Enter Elements for binary Search Tree:"<<endl;
    takeInput(root);

    cout<<"preorder traversal of tree is:"<<endl;
    preorder(root);
    return 0;
}