//https://www.luogu.com.cn/problem/P1115
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
LL a[N];

int main(){
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    LL sum = 0,ret = -1e6;
    for(int i = 1;i <= n;i++){
        sum +=a[i];
        ret =max(ret,sum);
        if(sum < 0){
            sum = 0;
        }
        
    }
    cout <<ret <<endl;
    return 0;
}