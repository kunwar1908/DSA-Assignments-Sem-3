#include <iostream>
#include <string>
using namespace std;

bool areParenthesesBalanced(const string& expr){ string s; for(char c:expr){ if(c=='('||c=='{'||c=='[') s.push_back(c); else if(c==')'||c=='}'||c==']'){ if(s.empty()) return false; char t=s.back(); s.pop_back(); if((c==')'&&t!='(')||(c=='}'&&t!='{')||(c==']'&&t!='[')) return false; } } return s.empty(); }

int main(){ string e1="{([])}", e2="([)]"; cout<<e1<<" -> "<<(areParenthesesBalanced(e1)?"BALANCED":"NOT BALANCED")<<"\n"; cout<<e2<<" -> "<<(areParenthesesBalanced(e2)?"BALANCED":"NOT BALANCED")<<"\n"; return 0; }
