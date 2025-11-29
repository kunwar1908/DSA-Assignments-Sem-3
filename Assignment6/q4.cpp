#include <iostream>
#include <vector>
using namespace std;
struct CLLNode{ int data; CLLNode* next; CLLNode(int v):data(v),next(nullptr){} };

CLLNode* createNonCircularList(const vector<int>& vals){ if(vals.empty()) return nullptr; CLLNode* h=new CLLNode(vals[0]); CLLNode* cur=h; for(size_t i=1;i<vals.size();++i){ cur->next=new CLLNode(vals[i]); cur=cur->next; } return h; }
bool isCircular(CLLNode* head){ if(!head) return false; CLLNode* slow=head; CLLNode* fast=head->next; while(fast && fast->next){ if(slow==fast) return true; slow=slow->next; fast=fast->next->next; } return false; }
int main(){ vector<int> v={10,20,30,40}; CLLNode* lin=createNonCircularList(v); cout<<"Linear is circular? "<<(isCircular(lin)?"True":"False")<<"\n"; // cleanup
    while(lin){ CLLNode* n=lin->next; delete lin; lin=n; } return 0; }
