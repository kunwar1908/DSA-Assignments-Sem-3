#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void problem4_Strings(){
    string s1="Hello, ", s2="World!", original_s="DaTa Structures", vowels_s="Programming Is FUN", sort_s="cbaedgfh";
    cout<<"(a) Concat: "<<s1+s2<<"\n";
    string rev=original_s; reverse(rev.begin(), rev.end()); cout<<"(b) Reverse: "<<rev<<"\n";
    string no_v=vowels_s; no_v.erase(remove_if(no_v.begin(), no_v.end(),[](char c){return string("aeiouAEIOU").find(c)!=string::npos;}), no_v.end()); cout<<"(c) No vowels: "<<no_v<<"\n";
    string s_sorted=sort_s; sort(s_sorted.begin(), s_sorted.end()); cout<<"(d) Sorted: "<<s_sorted<<"\n";
    char upper='X'; cout<<"(e) To lower: "<<(char)tolower(upper)<<"\n";
}

int main(){ problem4_Strings(); return 0; }
