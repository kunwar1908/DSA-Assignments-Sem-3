#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n-1;++i)
        for(int j=0;j<n-1-i;++j)
            if(a[j]>a[j+1]) swap(a[j], a[j+1]);
}
int main(){
    vector<int> a={5,1,4,2,8};
    cout<<"Bubble Sort - before:\n"; for(int x:a) cout<<x<<" "; cout<<"\n";
    bubbleSort(a);
    cout<<"after:\n"; for(int x:a) cout<<x<<" "; cout<<"\n";
    return 0;
}
