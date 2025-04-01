//https://www.luogu.com.cn/problem/P10452
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+10;
LL a[N];

int main(){
    LL n;cin >> n;
    for(LL i = 1;i <= n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    LL ret = 0;
    for(LL i = 1;i <=n/2;i++){
        ret+=abs(a[i] - a[n-i+1]);
    }
    cout << ret <<endl;
    return 0;
}
