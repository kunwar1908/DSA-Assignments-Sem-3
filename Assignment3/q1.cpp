#include <iostream>
using namespace std;

const int MAX_SIZE = 50;
class ArrayStack {
private:
    int arr[MAX_SIZE]; int top;
public:
    ArrayStack():top(-1){}
    bool isEmpty()const{return top==-1;} bool isFull()const{return top==MAX_SIZE-1;}
    void push(int data){ if(isFull()){ cout<<"Stack Overflow!"<<endl; return;} arr[++top]=data; cout<<data<<" pushed."<<endl; }
    int pop(){ if(isEmpty()){ cout<<"Stack Underflow!"<<endl; return -1;} return arr[top--]; }
    int peek()const{ if(isEmpty()){ cout<<"Empty"<<endl; return -1;} return arr[top]; }
    void display()const{ if(isEmpty()){ cout<<"Stack empty"<<endl; return;} cout<<"Stack (Top->Bottom): "; for(int i=top;i>=0;--i) cout<<arr[i]<<(i==0?"":" "); cout<<"\n"; }
};

int main(){ ArrayStack st; st.push(10); st.push(20); st.display(); cout<<"Popped: "<<st.pop()<<"\n"; cout<<"Peek: "<<st.peek()<<"\n"; return 0; }
