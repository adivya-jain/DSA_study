#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // default constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
}

void insertAtEnd(Node *&tail, int d)
{
    Node *temp = new Node(d);
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node* &Head,Node* &tail,int pos,int d)
{
    int cnt=1;
    if(pos==1)
    {
        insertAtHead(Head,d);
        return;
    }

    Node* Newnode= new Node(d);
    Node* temp=Head;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        insertAtEnd(tail,d);
        return;
    }
    Newnode->next=temp->next;
    temp->next=Newnode;
    

}

void print(Node *&Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *node1 = new Node(10);
    // cout<<"node1 data "<<node1->data<<endl;
    // cout<<"node1 address "<<node1->next;

    Node *Head = node1;
    Node *tail = node1;

    insertAtHead(Head, 20);
    insertAtHead(Head, 30);
    insertAtEnd(tail, 50);
    insertAtEnd(tail, 60);
    insertAtPosition(Head,tail,1,22);
    insertAtPosition(Head,tail,5,61);
    print(Head);
    return 0;
}