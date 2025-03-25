#include <iostream>

using namespace std;

const int N = 2e5+10;
int a[N],f[N];
int ret = -1e9;;
int n;
int main(){
    cin >> n;
    for(int i = 1;i < n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    int premin = 0;
    for(int i = 1;i <= n; i++){
        ret = max(ret,f[i] - premin);
        premin = min(premin,f[i]);
    }

    cout << ret<<endl;
    return 0;
}