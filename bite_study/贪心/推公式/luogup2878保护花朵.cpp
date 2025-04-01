//https://www.luogu.com.cn/problem/P2878
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
struct node{
    int t,d;
}cow[N];
bool cmp(const node &x,const node &y){
    return x.t*y.d<y.t*x.d;
}
int main(){
    LL n;cin >>n;
    for(LL i = 1;i <=n;i++){
        cin >>cow[i].t>>cow[i].d;
    }
    sort(cow+1,cow+1+n,cmp);
    LL time = 0,res = 0;
    for(LL i = 1;i <= n;i++){
        res +=cow[i].d * time;
        time +=cow[i].t*2;
    }
    cout << res <<endl;
    return 0;
}