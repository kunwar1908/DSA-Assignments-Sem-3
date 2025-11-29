#include <iostream>
using namespace std;

struct CLLNode{ int data; CLLNode* next; CLLNode(int v):data(v),next(nullptr){} };

class CircularLinkedList{ CLLNode* head; public: CircularLinkedList():head(nullptr){} ~CircularLinkedList(){ if(!head) return; CLLNode* cur=head->next; while(cur!=head){ CLLNode* n=cur->next; delete cur; cur=n; } delete head; }
    bool isEmpty()const{return head==nullptr;} void insertAtEnd(int v){ CLLNode* n=new CLLNode(v); if(isEmpty()){ head=n; n->next=head; cout<<"Inserted "<<v<<" as first\n"; return;} CLLNode* cur=head; while(cur->next!=head) cur=cur->next; cur->next=n; n->next=head; cout<<"Inserted "<<v<<" at end\n"; }
    void deleteSpecific(int targetVal){ if(isEmpty()){ cout<<"Empty\n"; return;} CLLNode* cur=head; CLLNode* prev=nullptr; do{ if(cur->data==targetVal){ if(cur==head && prev==nullptr){ delete head; head=nullptr; cout<<"Deleted only node\n"; return; } if(cur==head){ CLLNode* tail=head; while(tail->next!=head) tail=tail->next; head=head->next; tail->next=head; delete cur; cout<<"Deleted head\n"; return; } prev->next=cur->next; delete cur; cout<<"Deleted "<<targetVal<<"\n"; return; } prev=cur; cur=cur->next; } while(cur!=head); cout<<"Not found\n"; }
    bool searchNode(int targetVal)const{ if(isEmpty()) return false; CLLNode* cur=head; int pos=1; do{ if(cur->data==targetVal){ cout<<"Found at "<<pos<<"\n"; return true; } cur=cur->next; pos++; } while(cur!=head); cout<<"Not found\n"; return false; }
    void displayWithHeadRepeat()const{ if(isEmpty()){ cout<<"Empty\n"; return;} cout<<"CLL: "; CLLNode* cur=head; do{ cout<<cur->data<<" -> "; cur=cur->next; } while(cur!=head); cout<<head->data<<"\n"; }
    int getSize()const{ if(isEmpty()) return 0; int c=0; CLLNode* cur=head; do{ c++; cur=cur->next;} while(cur!=head); return c; }
    CLLNode* getHead()const{return head;} };

int main(){ CircularLinkedList cll; cll.insertAtEnd(20); cll.insertAtEnd(100); cll.insertAtEnd(40); cll.insertAtEnd(80); cll.insertAtEnd(60); cll.displayWithHeadRepeat(); cout<<"Size: "<<cll.getSize()<<"\n"; cll.deleteSpecific(40); cll.searchNode(80); cll.displayWithHeadRepeat(); return 0; }
