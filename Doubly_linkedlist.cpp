#include <iostream>
using namespace std;
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    };
};
// prints all the elements of linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
// gives length linked list
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);

    temp->next = Head;
    Head->prev = temp;
    Head = temp;
}
void insertAtTail(Node*& tail ,int d)
{
    Node* newnode=new Node(d);
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
     
}

void insertAtPositon(Node* &tail ,Node* &Head,int position,int d)
{
    if(position==1)
    {
        insertAtHead(Head,d);
        return;
    }
    Node* temp=Head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node* newnode =new Node(d);
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;

}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
 Node *tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 13);
    print(head);

    insertAtTail(tail, 16);
    print(head);

    insertAtPositon(tail,head,3, 16);
    print(head);

        insertAtPositon(tail,head,1, 26);
    print(head);
        insertAtPositon(tail,head,8, 16);
    print(head);
    cout << getLength(head);
    return 0;
}