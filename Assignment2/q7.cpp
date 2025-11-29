#include <iostream>
#include <vector>
using namespace std;

int countInversions(const vector<int>& arr) { int n=arr.size(); int cnt=0; for(int i=0;i<n-1;++i) for(int j=i+1;j<n;++j) if (arr[i]>arr[j]) cnt++; return cnt; }

int main(){ vector<int> arr={2,4,1,3,5}; cout<<"Array: "; for(int v:arr) cout<<v<<" "; cout<<"\nInversions: "<<countInversions(arr)<<"\n"; return 0; }
