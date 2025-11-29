#include <iostream>
using namespace std;

struct DLLNode{ int data; DLLNode* prev; DLLNode* next; DLLNode(int v):data(v),prev(nullptr),next(nullptr){} };

class DoublyLinkedList{ DLLNode* head; DLLNode* tail; public: DoublyLinkedList():head(nullptr),tail(nullptr){} ~DoublyLinkedList(){ DLLNode* cur=head; while(cur){ DLLNode* n=cur->next; delete cur; cur=n; } }
    bool isEmpty()const{return head==nullptr;} void display()const{ if(isEmpty()){ cout<<"DLL empty\n"; return;} DLLNode* cur=head; while(cur){ cout<<cur->data<<(cur->next?" <-> ":""); cur=cur->next;} cout<<"\n"; }
    void insert(int newVal,int targetVal=-1,bool after=true){ DLLNode* n=new DLLNode(newVal); if(isEmpty()){ head=tail=n; return;} if(targetVal==-1){ n->next=head; head->prev=n; head=n; return;} DLLNode* cur=head; while(cur && cur->data!=targetVal) cur=cur->next; if(!cur){ tail->next=n; n->prev=tail; tail=n; return;} if(after){ n->next=cur->next; n->prev=cur; if(cur->next) cur->next->prev=n; else tail=n; cur->next=n; } else { n->prev=cur->prev; n->next=cur; if(cur->prev) cur->prev->next=n; else head=n; cur->prev=n; } }
    void deleteSpecific(int targetVal){ if(isEmpty()){ cout<<"Empty\n"; return;} DLLNode* cur=head; while(cur && cur->data!=targetVal) cur=cur->next; if(!cur){ cout<<"Not found\n"; return;} if(cur->prev) cur->prev->next=cur->next; else head=cur->next; if(cur->next) cur->next->prev=cur->prev; else tail=cur->prev; cout<<"Deleted "<<cur->data<<"\n"; delete cur; }
    bool searchNode(int targetVal)const{ DLLNode* cur=head; int pos=1; while(cur){ if(cur->data==targetVal){ cout<<"Found at "<<pos<<"\n"; return true;} cur=cur->next; pos++; } cout<<"Not found\n"; return false; }
    int getSize()const{ int c=0; DLLNode* cur=head; while(cur){ c++; cur=cur->next; } return c; }
    DLLNode* getHead()const{return head;} DLLNode* getTail()const{return tail;} };

int main(){ DoublyLinkedList dll; dll.insert(10); dll.insert(50); dll.insert(30,10,true); dll.insert(20,30,false); dll.display(); cout<<"Size: "<<dll.getSize()<<"\n"; dll.searchNode(50); dll.deleteSpecific(10); dll.display(); return 0; }
