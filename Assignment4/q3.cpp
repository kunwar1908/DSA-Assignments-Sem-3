#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void interleaveQueue(queue<int>& q){ if(q.empty()||q.size()%2!=0){ cout<<"Queue must be non-empty and even-sized.\n"; return; } int half=q.size()/2; stack<int> s; for(int i=0;i<half;++i){ s.push(q.front()); q.pop(); } while(!s.empty()){ q.push(s.top()); s.pop(); q.push(q.front()); q.pop(); } }

int main(){ queue<int> q; vector<int> in={4,7,11,20,5,9}; for(int v:in) q.push(v); cout<<"Original: "; queue<int> tmp=q; while(!tmp.empty()){ cout<<tmp.front()<<" "; tmp.pop(); } cout<<"\n"; interleaveQueue(q); cout<<"Interleaved: "; while(!q.empty()){ cout<<q.front()<<" "; q.pop(); } cout<<"\n"; return 0; }
