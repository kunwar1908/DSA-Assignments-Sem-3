#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Compact storage helpers for special matrices
// 1) Diagonal matrix: store only diagonal elements in 1D array of size n
struct DiagonalMatrix {
	int n; vector<int> a; DiagonalMatrix(int n=0):n(n),a(n){}
	void set(int i,int j,int val){ if(i!=j && val!=0) throw runtime_error("Non-diagonal element non-zero"); if(i==j) a[i]=val; }
	int get(int i,int j) const { return (i==j)?a[i]:0; }
};

// 2) Tridiagonal: store diagonals (main, upper, lower) in arrays of sizes n, n-1, n-1
struct Tridiagonal {
	int n; vector<int> lower, main, upper; Tridiagonal(int n=0):n(n),lower(max(0,n-1)),main(n),upper(max(0,n-1)){}
	void set(int i,int j,int val){ if(i==j) main[i]=val; else if(i==j+1) lower[j]=val; else if(i+1==j) upper[i]=val; else if(val!=0) throw runtime_error("Only tri-diagonal positions allowed"); }
	int get(int i,int j) const { if(i==j) return main[i]; if(i==j+1) return lower[j]; if(i+1==j) return upper[i]; return 0; }
};

// 3) Lower triangular (store row-wise in 1D): index(i,j) -> i*(i+1)/2 + j  for 0<=j<=i
struct LowerTriangular {
	int n; vector<int> a; LowerTriangular(int n=0):n(n),a(n*(n+1)/2){}
	void set(int i,int j,int val){ if(j>i){ if(val!=0) throw runtime_error("Upper element must be zero"); return;} a[i*(i+1)/2 + j]=val; }
	int get(int i,int j) const { if(j>i) return 0; return a[i*(i+1)/2 + j]; }
};

// 4) Upper triangular (store row-wise using mapping for j>=i)
struct UpperTriangular {
	int n; vector<int> a; UpperTriangular(int n=0):n(n),a(n*(n+1)/2){}
	void set(int i,int j,int val){ if(i>j){ if(val!=0) throw runtime_error("Lower element must be zero"); return;} // map (i,j) to index
		int idx = i*n - (i*(i-1))/2 + (j-i);
		a[idx]=val;
	}
	int get(int i,int j) const { if(i>j) return 0; int idx = i*n - (i*(i-1))/2 + (j-i); return a[idx]; }
};

// 5) Symmetric: store upper-triangular including diagonal in 1D with mapping
struct SymmetricMatrix {
	int n; vector<int> a; SymmetricMatrix(int n=0):n(n),a(n*(n+1)/2){}
	void set(int i,int j,int val){ if(i<=j){ int idx = i*n - (i*(i-1))/2 + (j-i); a[idx]=val; } else { set(j,i,val); } }
	int get(int i,int j) const { if(i<=j){ int idx = i*n - (i*(i-1))/2 + (j-i); return a[idx]; } else return get(j,i); }
};

int main(){
	cout<<"Assignment2 - q5: Compact storage demos"<<"\n\n";
	int n=4;
	DiagonalMatrix D(n); for(int i=0;i<n;++i) D.set(i,i,(i+1)*10);
	cout<<"Diagonal stored (n="<<n<<"):\n"; for(int i=0;i<n;++i){ for(int j=0;j<n;++j) cout<<D.get(i,j)<<" "; cout<<"\n"; }

	Tridiagonal T(n); T.set(0,0,1); T.set(0,1,2); T.set(1,0,3); T.set(1,1,4); T.set(1,2,5); T.set(2,1,6); T.set(2,2,7); T.set(2,3,8); T.set(3,2,9); T.set(3,3,10);
	cout<<"\nTri-diagonal matrix:\n"; for(int i=0;i<n;++i){ for(int j=0;j<n;++j) cout<<T.get(i,j)<<" "; cout<<"\n"; }

	LowerTriangular L(n); for(int i=0;i<n;++i) for(int j=0;j<=i;++j) L.set(i,j,i+j+1);
	cout<<"\nLower triangular:\n"; for(int i=0;i<n;++i){ for(int j=0;j<n;++j) cout<<L.get(i,j)<<" "; cout<<"\n"; }

	UpperTriangular U(n); for(int i=0;i<n;++i) for(int j=i;j<n;++j) U.set(i,j,(i+1)*(j+1));
	cout<<"\nUpper triangular:\n"; for(int i=0;i<n;++i){ for(int j=0;j<n;++j) cout<<U.get(i,j)<<" "; cout<<"\n"; }

	SymmetricMatrix S(n); for(int i=0;i<n;++i) for(int j=i;j<n;++j) S.set(i,j,i+j+2);
	cout<<"\nSymmetric matrix:\n"; for(int i=0;i<n;++i){ for(int j=0;j<n;++j) cout<<S.get(i,j)<<" "; cout<<"\n"; }

	return 0;
}
