#include <iostream>
#include <string>
using namespace std;

int applyOp(int a,int b,char op){ switch(op){case '+':return a+b;case '-':return a-b;case '*':return a*b;case '/': if(b==0) throw runtime_error("Division by zero"); return a/b;} return 0; }
int evaluatePostfix(const string& postfix){ string val_stack; for(char token:postfix){ if(isdigit(token)){ val_stack.push_back(token-'0'); } else if(token=='+'||token=='-'||token=='*'||token=='/'){ if(val_stack.size()<2) throw runtime_error("Invalid"); int v2=val_stack.back(); val_stack.pop_back(); int v1=val_stack.back(); val_stack.pop_back(); int res=applyOp(v1,v2,token); val_stack.push_back(res); } } if(val_stack.size()==1) return val_stack.back(); throw runtime_error("Invalid"); }

int main(){ string postfix="231*+9-"; try{ int r=evaluatePostfix(postfix); cout<<"Postfix: "<<postfix<<" -> "<<r<<"\n"; } catch(const exception& e){ cerr<<"Error: "<<e.what()<<"\n"; } return 0; }
