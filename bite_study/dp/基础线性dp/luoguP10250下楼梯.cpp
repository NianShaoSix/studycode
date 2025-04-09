//https://www.luogu.com.cn/problem/P10250
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 65;
int n;
LL dp[N];

int main(){
    cin >> n;
    // dp[0] = 1;
    // dp[1] = 1;
    // dp[2] = 2;
    // for(int i = 3;i <= n;i++){
    //     dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    // }    
    // cout << dp[n]<<endl;
    int a = 1,b = 1,c = 2;
    int t = 0;
    for(int i = 3;i <= n;i++){
        t = a + b + c;
        a = b;
        b = c;
        c = t;
    }
    if(n == 1) cout << b <<endl;
    else cout << c <<endl;
    return 0;
}