#include <iostream>
using namespace std;

int main() {
    const int R=3,C=4;
    int M[R][C] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout<<"Matrix:\n"; for(int i=0;i<R;++i){ for(int j=0;j<C;++j) cout<<M[i][j]<<"\t"; cout<<"\n"; }
    for(int i=0;i<R;++i){ int sum=0; for(int j=0;j<C;++j) sum+=M[i][j]; cout<<"Row "<<i<<" sum: "<<sum<<"\n"; }
    for(int j=0;j<C;++j){ int sum=0; for(int i=0;i<R;++i) sum+=M[i][j]; cout<<"Col "<<j<<" sum: "<<sum<<"\n"; }
    return 0;
}
