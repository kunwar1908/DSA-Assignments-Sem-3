#include <iostream>
#include <algorithm>
using namespace std;

void reverseArrayDemo() {
    int a[] = {10,20,30,40,50,60}; int n = sizeof(a)/sizeof(a[0]);
    cout << "Original: ["; for (int i=0;i<n;++i) cout<<a[i]<<(i+1==n?"":", "); cout<<"]\n";
    int i=0,j=n-1; while(i<j) swap(a[i++],a[j--]);
    cout<<"Reversed: ["; for (int k=0;k<n;++k) cout<<a[k]<<(k+1==n?"":", "); cout<<"]\n";
}

void matrixMultiplicationDemo() {
    const int R1=2,C1=3,R2=3,C2=2;
    int A[R1][C1]={{1,2,3},{4,5,6}}; int B[R2][C2]={{7,8},{9,10},{11,12}}; int C[R1][C2] = {0};
    for(int i=0;i<R1;++i) for(int j=0;j<C2;++j) for(int k=0;k<C1;++k) C[i][j]+=A[i][k]*B[k][j];
    cout<<"Matrix C:\n"; for(int i=0;i<R1;++i){ for(int j=0;j<C2;++j) cout<<C[i][j]<<"\t"; cout<<"\n"; }
}

void transposeDemo() {
    const int R=3,C=2; int A[R][C]={{1,2},{3,4},{5,6}}; int T[C][R];
    for(int i=0;i<R;++i) for(int j=0;j<C;++j) T[j][i]=A[i][j];
    cout<<"Transpose:\n"; for(int i=0;i<C;++i){ for(int j=0;j<R;++j) cout<<T[i][j]<<"\t"; cout<<"\n"; }
}

int main(){ reverseArrayDemo(); matrixMultiplicationDemo(); transposeDemo(); return 0; }
