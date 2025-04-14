#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1e3 + 10;
LL ret;
LL a[N],b[N],c[N];
int n,m;
LL x[4];
LL solve(){

    LL sum = 0;
    LL t1 = a[x[1]%n],t2 = b[x[2]%n],t3 = c[x[3]%n];
    if(t1 == t2&& t2 == t3&& t1 == t3){
        sum = 200;
    }
    if((t1==t2&&t1!=t3)||(t2 == t3&&t1!=t2)||(t1==t3&&t1!=t2)){
        sum = 100;
    }
    if(t1 < t2 && t2*2==t1+t3&&t2<t3){
        sum = 200;
    }
    if((t1!=t2&&t1*2==t2+t3)||(t1>t2&&t2*2==t1+t3)||(t1!=t2&&t3*2==t1+t2)){
        sum = 100;
    }
    return sum;
}
int main(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >>a[i];
    for(int i = 0;i < n;i++) cin >>b[i];
    for(int i = 0;i < n;i++) cin >>c[i];
    cin >> m;
    while(m--){
        LL e,f,g;cin >> e>>f>>g;
        x[1]+=e;
        x[2]+=f;
        x[3]+=g;
        ret+=solve();
    }
    cout << ret<<endl;
    return 0;
}