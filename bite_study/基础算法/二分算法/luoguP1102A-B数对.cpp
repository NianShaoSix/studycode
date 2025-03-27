//https://www.luogu.com.cn/problem/P1102
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 2e5+10;
LL n,c;
LL a[N];
int main(){
    cin >> n >> c;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    LL ret = 0;
    for(int i = 2;i <= n;i++){
        ret+=upper_bound(a + 1,a + i,a[i] - c) - lower_bound(a + 1,a + i,a[i]-c);
    }
    cout << ret <<endl;
    return 0;
}