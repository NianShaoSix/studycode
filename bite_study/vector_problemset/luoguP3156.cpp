#include <iostream>
#include <vector>
const int N = 2e6+20;
using namespace std;
int n,m;
int main() {
    vector<int>a(N);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int y;
        cin >> y;
        cout << a[y-1];
        puts("");
    }
    return 0;
}