#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& a){
    for(size_t i=1;i<a.size();++i){
        int key=a[i]; int j=i-1;
        while(j>=0 && a[j]>key){ a[j+1]=a[j]; if(j==0){ --j; break;} --j; }
        a[j+1]=key;
    }
}
int main(){
    vector<int> a={12,11,13,5,6};
    cout<<"Insertion Sort - before:\n"; for(int x:a) cout<<x<<" "; cout<<"\n";
    insertionSort(a);
    cout<<"after:\n"; for(int x:a) cout<<x<<" "; cout<<"\n";
    return 0;
}
