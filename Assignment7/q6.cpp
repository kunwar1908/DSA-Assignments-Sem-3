#include <iostream>
#include <vector>
using namespace std;
void dualSelectionSort(vector<int>& a){
    int left=0, right=(int)a.size()-1;
    while(left<right){
        int minIdx=left, maxIdx=left;
        for(int i=left;i<=right;++i){ if(a[i]<a[minIdx]) minIdx=i; if(a[i]>a[maxIdx]) maxIdx=i; }
        swap(a[left], a[minIdx]);
        // if max was at left, its index moved to minIdx
        if(maxIdx==left) maxIdx=minIdx;
        swap(a[right], a[maxIdx]);
        ++left; --right;
    }
}
int main(){
    vector<int> a={29,10,14,37,13,5,2};
    cout<<"Dual-Selection Sort - before:\n"; for(int x:a) cout<<x<<" "; cout<<"\n";
    dualSelectionSort(a);
    cout<<"after:\n"; for(int x:a) cout<<x<<" "; cout<<"\n";
    return 0;
}
