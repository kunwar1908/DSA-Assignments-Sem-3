#include <iostream>
using namespace std;

struct DLLNode{ int data; DLLNode* prev; DLLNode* next; DLLNode(int v):data(v),prev(nullptr),next(nullptr){} };

bool isPalindromeDLL(DLLNode* head, DLLNode* tail){ if(!head||head==tail) return true; DLLNode* f=head; DLLNode* b=tail; while(f!=b && f->prev!=b){ if(f->data!=b->data) return false; f=f->next; b=b->prev; } return true; }

int main(){ // build example
    DLLNode* a=new DLLNode('L'); DLLNode* b=new DLLNode('E'); DLLNode* c=new DLLNode('V'); DLLNode* d=new DLLNode('E'); DLLNode* e=new DLLNode('L');
    a->next=b; b->prev=a; b->next=c; c->prev=b; c->next=d; d->prev=c; d->next=e; e->prev=d;
    cout<<"Is palindrome: "<<(isPalindromeDLL(a,e)?"True":"False")<<"\n";
    // cleanup
    delete a; delete b; delete c; delete d; delete e; return 0; }
