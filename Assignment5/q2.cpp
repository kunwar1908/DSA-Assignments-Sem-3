#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

int countAndDelete(Node*& head, int key){ int count=0; while(head && head->data==key){ Node* t=head; head=head->next; delete t; count++; } Node* cur=head; Node* prev=nullptr; while(cur){ if(cur->data==key){ prev->next=cur->next; Node* t=cur; cur=cur->next; delete t; count++; } else{ prev=cur; cur=cur->next; } } return count; }

int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(1); head->next->next->next=new Node(2); head->next->next->next->next=new Node(1); head->next->next->next->next->next=new Node(3); head->next->next->next->next->next->next=new Node(1);
    // display
    Node* t=head; cout<<"Original: "; while(t){ cout<<t->data<<" "; t=t->next;} cout<<"\n";
    int cnt=countAndDelete(head,1);
    cout<<"Count deleted: "<<cnt<<"\nUpdated: "; t=head; while(t){ cout<<t->data<<" "; t=t->next;} cout<<"\n";
    // cleanup
    while(head){ Node* n=head->next; delete head; head=n; }
    return 0; }
