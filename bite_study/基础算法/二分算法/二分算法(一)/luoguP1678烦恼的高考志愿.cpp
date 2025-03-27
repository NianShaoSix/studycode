//https://www.luogu.com.cn/problem/P1678
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N];LL q;
LL ret;
int main(){
    LL m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+m);
    while(n--){
        LL x;cin >> x;
        auto it = lower_bound(a+1,a+m+1,x);
        auto right = it;
        
        if(*right!=a[1]) it--;
        ret+=min((abs(*right - x)),(abs(*it - x)));
    }
    cout <<ret <<endl;
    return 0;
}