#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues { queue<int> q1,q2; public: void push(int d){ while(!q1.empty()){ q2.push(q1.front()); q1.pop(); } q1.push(d); while(!q2.empty()){ q1.push(q2.front()); q2.pop(); } cout<<d<<" pushed (O(n))\n";} int pop(){ if(q1.empty()){ cout<<"Empty\n"; return -1; } int v=q1.front(); q1.pop(); return v; } };

class StackUsingOneQueue{ queue<int> q; public: void push(int d){ q.push(d); cout<<d<<" pushed (O(1))\n";} int pop(){ if(q.empty()){ cout<<"Empty\n"; return -1;} int n=q.size(); for(int i=0;i<n-1;++i){ q.push(q.front()); q.pop(); } int v=q.front(); q.pop(); return v; } };

int main(){ StackUsingTwoQueues s2; s2.push(10); s2.push(20); cout<<"Popped: "<<s2.pop()<<"\n"; StackUsingOneQueue s1; s1.push(100); s1.push(200); cout<<"Popped: "<<s1.pop()<<"\n"; return 0; }
