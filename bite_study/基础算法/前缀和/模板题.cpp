#include <iostream>

using namespace std;
typedef long long LL;
LL ret;
const int N = 1e8+10;
LL a[N],f[N];
int main(){
    int n,q;
    cin >>n>> q;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    
    int l,r;

    while(q--){
        cin >> l >> r;
        ret  = f[r] - f[l-1];
        cout << ret <<endl;
    }

    return 0;
}