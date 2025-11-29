#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 5;
class SimpleQueue { int arr[MAX_SIZE]; int front, rear; public: SimpleQueue():front(-1),rear(-1){} bool isEmpty()const{return front==-1;} bool isFull()const{return rear==MAX_SIZE-1;} void enqueue(int d){ if(isFull()){ cout<<"Overflow"<<endl; return;} if(isEmpty()) front=0; arr[++rear]=d; cout<<d<<" enqueued\n";} int dequeue(){ if(isEmpty()){ cout<<"Underflow\n"; return -1;} int v=arr[front++]; if(front>rear){ front=rear=-1;} return v;} int peek()const{ if(isEmpty()){ cout<<"Empty\n"; return -1;} return arr[front]; } void display() const { if(isEmpty()){ cout<<"Empty\n"; return;} cout<<"Queue: "; for(int i=front;i<=rear;++i) cout<<arr[i]<<(i==rear?"":" "); cout<<"\n"; }};

int main(){ SimpleQueue q; q.enqueue(10); q.enqueue(20); q.enqueue(30); q.display(); cout<<"Peek: "<<q.peek()<<"\n"; cout<<"Dequeued: "<<q.dequeue()<<"\n"; q.display(); return 0; }
