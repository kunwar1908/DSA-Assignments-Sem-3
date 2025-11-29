#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op){ if(op=='+'||op=='-') return 1; if(op=='*'||op=='/') return 2; if(op=='^') return 3; return 0; }
string infixToPostfix(const string& infix){ string postfix="", op_stack=""; for(char token:infix){ if(isalnum(token)) postfix+=token; else if(token=='(') op_stack.push_back(token); else if(token==')'){ while(!op_stack.empty() && op_stack.back()!='('){ postfix+=op_stack.back(); op_stack.pop_back(); } if(!op_stack.empty()&&op_stack.back()=='(') op_stack.pop_back(); } else { while(!op_stack.empty() && precedence(op_stack.back())>=precedence(token)){ postfix+=op_stack.back(); op_stack.pop_back(); } op_stack.push_back(token); } } while(!op_stack.empty()){ postfix+=op_stack.back(); op_stack.pop_back(); } return postfix; }

int main(){ string infix="a+b*(c-d)/e"; cout<<"Infix: "<<infix<<"\nPostfix: "<<infixToPostfix(infix)<<"\n"; return 0; }
