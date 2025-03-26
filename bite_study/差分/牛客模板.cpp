#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e6+10;
LL n,m,l,r,k;
LL a[N],f[N];
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        f[i] = a[i] - a[i-1];
    }
    while(m--){
        cin >> l >> r >>k;
        f[l] +=k;
        f[r+1]-=k;
    }
    LL temp = a[0];
    for(int i = 1;i <= n;i++){
        
        cout << temp + f[i]<<" ";
        temp += f[i];
    }

    return 0;
}