//https://www.luogu.com.cn/problem/P1226
#include <iostream>

using namespace std;
typedef long long LL;
//快速幂模板
LL qpow(LL a,LL b,LL p){
    LL ret = 1;
    while(b){
        if(b & 1 == 1) ret = ret * a % p;
            a = a * a % p;
            b >>=1;
    }
    return ret;
}

int main(){

    LL a,b,p;
    cin >> a>> b >>p;
    printf("%lld^%lld mod %lld=%lld",a,b,p,qpow(a,b,p));

    return 0;
}