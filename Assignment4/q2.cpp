#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 5;
class CircularQueue { int arr[MAX_SIZE]; int front, rear; public: CircularQueue():front(-1),rear(-1){} bool isEmpty()const{return front==-1;} bool isFull()const{return (rear+1)%MAX_SIZE==front;} void enqueue(int d){ if(isFull()){ cout<<"Overflow\n"; return;} if(isEmpty()) front=0; rear=(rear+1)%MAX_SIZE; arr[rear]=d; cout<<d<<" enqueued\n";} int dequeue(){ if(isEmpty()){ cout<<"Underflow\n"; return -1;} int v=arr[front]; if(front==rear){ front=rear=-1; } else front=(front+1)%MAX_SIZE; return v;} int peek()const{ if(isEmpty()){ cout<<"Empty\n"; return -1;} return arr[front]; } void display() const { if(isEmpty()){ cout<<"Empty\n"; return;} cout<<"Circular Queue: "; int i=front; do{ cout<<arr[i]; if(i!=rear) cout<<" "; i=(i+1)%MAX_SIZE; } while(i!=(rear+1)%MAX_SIZE); cout<<"\n"; }};

int main(){ CircularQueue cq; cq.enqueue(1); cq.enqueue(2); cq.enqueue(3); cq.display(); cout<<"Dequeued: "<<cq.dequeue()<<"\n"; cq.display(); cq.enqueue(4); cq.enqueue(5); cq.enqueue(6); // overflow
    cq.display(); return 0; }
