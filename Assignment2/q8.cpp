#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countDistinctElements(const vector<int>& arr) { if (arr.empty()) return 0; vector<int> tmp=arr; sort(tmp.begin(), tmp.end()); auto it=unique(tmp.begin(), tmp.end()); return distance(tmp.begin(), it); }

int main(){ vector<int> arr={10,20,10,30,40,20,50}; cout<<"Array: "; for(int v:arr) cout<<v<<" "; cout<<"\nDistinct count: "<<countDistinctElements(arr)<<"\n"; return 0; }
