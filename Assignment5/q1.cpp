#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int v):data(v),next(nullptr){} };

class SinglyLinkedList{ Node* head; public: SinglyLinkedList():head(nullptr){} ~SinglyLinkedList(){ Node* cur=head; while(cur){ Node* nx=cur->next; delete cur; cur=nx;} }
    void insertAtBeginning(int v){ Node* n=new Node(v); n->next=head; head=n; cout<<"Inserted "<<v<<" at beginning\n"; }
    void insertAtEnd(int v){ Node* n=new Node(v); if(!head){ head=n; return;} Node* cur=head; while(cur->next) cur=cur->next; cur->next=n; cout<<"Inserted "<<v<<" at end\n"; }
    void insertInBetween(int newVal,int target,bool before){ if(!head){ cout<<"Empty\n"; return; } Node* cur=head; Node* prev=nullptr; while(cur && cur->data!=target){ prev=cur; cur=cur->next; } if(!cur){ cout<<"Target not found\n"; return; } Node* n=new Node(newVal); if(before){ if(prev==nullptr){ insertAtBeginning(newVal); delete n; return;} n->next=cur; prev->next=n; cout<<"Inserted before\n"; } else{ n->next=cur->next; cur->next=n; cout<<"Inserted after\n"; } }
    void deleteFromBeginning(){ if(!head){ cout<<"Empty\n"; return;} Node* t=head; head=head->next; cout<<"Deleted "<<t->data<<" from beginning\n"; delete t; }
    void deleteFromEnd(){ if(!head){ cout<<"Empty\n"; return;} if(!head->next){ cout<<"Deleted "<<head->data<<"\n"; delete head; head=nullptr; return;} Node* cur=head; Node* prev=nullptr; while(cur->next){ prev=cur; cur=cur->next; } prev->next=nullptr; cout<<"Deleted "<<cur->data<<" from end\n"; delete cur; }
    void deleteSpecificNode(int val){ if(!head){ cout<<"Empty\n"; return;} if(head->data==val){ Node* t=head; head=head->next; cout<<"Deleted head "<<t->data<<"\n"; delete t; return;} Node* cur=head; Node* prev=nullptr; while(cur && cur->data!=val){ prev=cur; cur=cur->next; } if(!cur){ cout<<"Not found\n"; return;} prev->next=cur->next; cout<<"Deleted "<<cur->data<<"\n"; delete cur; }
    void searchNode(int val)const{ if(!head){ cout<<"Empty\n"; return;} Node* cur=head; int pos=1; while(cur){ if(cur->data==val){ cout<<"Found at pos "<<pos<<"\n"; return;} cur=cur->next; pos++; } cout<<"Not found\n"; }
    void display()const{ if(!head){ cout<<"Empty\n"; return;} Node* cur=head; while(cur){ cout<<cur->data<<(cur->next?" -> ":""); cur=cur->next;} cout<<"\n"; }
    Node* getHead()const{return head;} void setHead(Node* h){ head=h; }
};

int main(){ SinglyLinkedList list; list.insertAtBeginning(10); list.insertAtEnd(20); list.insertInBetween(15,20,true); list.display(); list.deleteFromBeginning(); list.display(); list.searchNode(20); return 0; }
