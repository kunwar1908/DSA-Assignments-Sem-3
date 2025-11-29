#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

struct Triplet { int row, col, val; };

// Normalize triplet list by sorting on (row,col)
static vector<Triplet> normalize(const vector<Triplet>& t){
    vector<Triplet> r=t; if(r.empty()) return r;
    sort(r.begin(), r.end(), [](const Triplet&a,const Triplet&b){ if(a.row!=b.row) return a.row<b.row; return a.col<b.col; });
    return r;
}

vector<Triplet> transposeSparseMatrix(const vector<Triplet>& sparse) {
    vector<Triplet> trans;
    for(const auto &e: sparse) trans.push_back({e.col,e.row,e.val});
    return normalize(trans);
}

vector<Triplet> addSparse(const vector<Triplet>& A, const vector<Triplet>& B){
    auto a=normalize(A); auto b=normalize(B);
    vector<Triplet> res; size_t i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i].row==b[j].row && a[i].col==b[j].col){ int s=a[i].val+b[j].val; if(s!=0) res.push_back({a[i].row,a[i].col,s}); ++i;++j; }
        else if(a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col)){ res.push_back(a[i++]); }
        else { res.push_back(b[j++]); }
    }
    while(i<a.size()) res.push_back(a[i++]); while(j<b.size()) res.push_back(b[j++]);
    return res;
}

// Multiply two sparse matrices A (m x p) and B (p x n)
vector<Triplet> multiplySparse(const vector<Triplet>& A, const vector<Triplet>& B){
    if(A.empty() || B.empty()) return {};
    // Build row-wise map for A and col-wise map for B
    map<int, vector<pair<int,int>>> rowsA; // row -> (col,val)
    map<int, vector<pair<int,int>>> colsB; // col -> (row,val)
    for(const auto &t: A) rowsA[t.row].push_back({t.col,t.val});
    for(const auto &t: B) colsB[t.col].push_back({t.row,t.val});

    vector<Triplet> C;
    for(const auto &ra: rowsA){ int i=ra.first; // row i
        unordered_map<int,long long> accum; // column -> value
        for(auto &p: ra.second){ int j=p.first; int valA=p.second; // multiply row i of A by columns of B where row==j
            // find columns k in B where B.row == j -> B entries (j,k,val)
            for(const auto &tb: B){ if(tb.row==j){ accum[tb.col] += (long long)valA * tb.val; } }
        }
        for(auto &kv: accum) if(kv.second!=0) C.push_back(Triplet{i, kv.first, (int)kv.second});
    }
    return normalize(C);
}

void printTriplets(const vector<Triplet>& t){ if(t.empty()){ cout<<"(empty)\n"; return;} for(auto &e: t) cout<<"("<<e.row<<","<<e.col<<","<<e.val<<")\n"; }

int main(){
    vector<Triplet> A = { {0,0,1}, {0,2,2}, {1,1,3} };
    vector<Triplet> B = { {0,0,4}, {0,1,5}, {2,0,6} };

    cout<<"A triplets:\n"; printTriplets(normalize(A));
    cout<<"B triplets:\n"; printTriplets(normalize(B));

    cout<<"\nA + B =\n"; auto S=addSparse(A,B); printTriplets(S);
    cout<<"\nTranspose(A) =\n"; auto T=transposeSparseMatrix(A); printTriplets(T);
    cout<<"\nA * B =\n"; auto M=multiplySparse(A,B); printTriplets(M);
    return 0;
}
