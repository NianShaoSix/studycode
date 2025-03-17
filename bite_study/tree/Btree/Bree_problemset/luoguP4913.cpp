#include <iostream>
using namespace std;
int n;
const int N = 1e6+10;
int l[N],r[N];
int  dfs(int u){
    if(!u) return 0;
    int a = dfs(l[u]);
    int b = dfs(r[u]);
    return a > b?(a+1):(b+1);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> l[i] >> r[i];
    }
    cout << dfs(1);
    return 0;
}