#include<iostream>
using namespace std;
class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

//Recursive approach - 1
void reverse(Node *&head, Node *&curr, Node *&prev) {
  if (curr == NULL) {
    head = prev;
    return;
  }
  Node *forward = curr->next;
  reverse(head, forward, curr);
  curr->next = prev;
}
Node *reverseLinkedList(Node *head) {


  Node *curr = head;
  Node *prev = NULL;
  reverse(head, curr, prev);
  return head;
  // Iterative approach -2

  // if(head==NULL || head->next==NULL)
  // {
  //     return head;
  // }

  // Node* prev =NULL;
  // Node* curr =head;
  // Node* forward=curr->next;

  // while(curr!=NULL)
  // {
  //     forward=curr->next;
  //     curr->next=prev;
  //     prev=curr;
  //     curr=forward;
  // }

  // return prev;
}