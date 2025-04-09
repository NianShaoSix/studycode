//https://www.luogu.com.cn/problem/P1115
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL dp[N];
int main(){
    int n;cin >>n;
    LL ret = -1e9;
    for(int i = 1;i <= n;i++){
        LL x;
        cin >>x;
        dp[i] = max(x,dp[i-1]+x);
        ret= max(dp[i],ret);
    }
    
    cout <<ret<<endl;
    
    return 0;
}