#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

void findFirstNonRepeating(const string& str){ queue<char> q; map<char,int> freq; cout<<"Input: "<<str<<"\nOutput: "; for(char c: str){ freq[c]++; if(freq[c]==1) q.push(c); while(!q.empty() && freq[q.front()]>1) q.pop(); if(q.empty()) cout<<"-1 "; else cout<<q.front()<<" "; } cout<<"\n"; }

int main(){ findFirstNonRepeating("aabcbcd"); return 0; }
