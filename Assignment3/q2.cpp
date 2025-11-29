#include <iostream>
#include <string>
using namespace std;

string reverseString(const string& str){ string s; for(char c: str) s.push_back(c); string res=""; while(!s.empty()){ res.push_back(s.back()); s.pop_back(); } return res; }

int main(){ string input="DataStructure"; cout<<"Original: "<<input<<"\nReversed: "<<reverseString(input)<<"\n"; return 0; }
