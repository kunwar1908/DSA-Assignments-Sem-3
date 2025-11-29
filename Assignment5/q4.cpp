#include <iostream>
using namespace std;
struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

Node* reverseList(Node* head){ Node* cur=head; Node* prev=nullptr; Node* next=nullptr; while(cur){ next=cur->next; cur->next=prev; prev=cur; cur=next; } return prev; }

int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); cout<<"Original: "; Node* t=head; while(t){ cout<<t->data<<" "; t=t->next;} cout<<"\n"; Node* r=reverseList(head); cout<<"Reversed: "; t=r; while(t){ cout<<t->data<<" "; t=t->next;} cout<<"\n"; // cleanup
    while(r){ Node* n=r->next; delete r; r=n; } return 0; }
