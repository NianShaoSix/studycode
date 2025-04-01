//https://www.luogu.com.cn/problem/P1842
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 5e4 + 10;
struct node{
    LL w,s;
}a[N];

bool cmp(const node&x,const node&y){
    return max(-x.s,x.w-y.s)<max(-y.s,y.w-x.s);
}

int main(){
    LL n;cin >> n;
    for(LL i = 1;i <= n;i++){
        cin >>a[i].w>>a[i].s;
    }

    sort(a+1,a+1+n,cmp);
    LL res = -1e9-10,w = 0;
    for(LL i = 1;i <= n;i++){
        res=max(res,w-a[i].s);
        w+=a[i].w;
    }
    cout << res <<endl;
    return 0;
}