#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // assuming the element is present in the list

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming the element is in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found and current is representing the element node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *&tail)
{
    if(tail==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deletion(Node *&tail, int d)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty ,please check the list again";
        return;
    }
    else
    {
        // non empty
        Node* prev = tail;
        Node* curr = prev->next;
        while (curr->data != d)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        //1 Node Linked List
        if(curr==prev)
        {
            tail=NULL;
        }
        //>=2 Node linked list
        if(tail== curr)
        {
            tail=prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
    // empty list me insert krre hai
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 3, 4);
    print(tail);
    deletion(tail, 3);
    print(tail);
    cout<<tail->data<<endl;
}