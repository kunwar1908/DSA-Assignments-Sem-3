#include <iostream>
#include <vector>
using namespace std;

int findMissingLinear(const vector<int>& arr, int n) {
    long long expected = (long long)n*(n+1)/2; long long actual=0; for(int v:arr) actual+=v; return (int)(expected-actual);
}

int findMissingBinary(const vector<int>& arr, int n) {
    int low=0, high=arr.size()-1; if (arr[high]==high+1) return n;
    while(low<=high){ int mid=low+(high-low)/2; if (arr[mid]!=mid+1){ if (mid==0||arr[mid-1]==mid) return mid+1; high=mid-1;} else low=mid+1; }
    return -1;
}

int main(){ vector<int> arr={1,2,4,5,6,7}; int n=arr.size()+1; cout<<"Missing (linear): "<<findMissingLinear(arr,n)<<"\n"; cout<<"Missing (binary): "<<findMissingBinary(arr,n)<<"\n"; return 0; }
