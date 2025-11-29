#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> data = {5,2,8,2,5,1,9,8,10,5};
    cout << "Original: [";
    for (size_t i=0;i<data.size();++i) cout << data[i] << (i+1==data.size()?"":", ");
    cout << "]\n";
    sort(data.begin(), data.end());
    auto it = unique(data.begin(), data.end());
    data.erase(it, data.end());
    cout << "Unique: [";
    for (size_t i=0;i<data.size();++i) cout << data[i] << (i+1==data.size()?"":", ");
    cout << "]\n";
    return 0;
}
