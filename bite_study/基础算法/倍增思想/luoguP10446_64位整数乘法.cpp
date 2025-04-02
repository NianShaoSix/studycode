//https://www.luogu.com.cn/problem/P10446
#include <iostream>
using namespace std;
typedef long long LL;

LL qmul(LL a,LL b ,LL p){
    LL ret = 0;
    while(b){
        if(b&1) ret=(ret+a)%p;
        a = (a+a)%p;
        b>>=1;
    }
    return ret;
}

int main(){

    LL a,b,p;cin >> a>>b >>p;
    cout <<qmul(a,b,p);

}