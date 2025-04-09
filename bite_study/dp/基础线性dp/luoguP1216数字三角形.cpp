//https://www.luogu.com.cn/problem/P1216
#include <iostream>

using namespace std;

const int N = 1010;
typedef long long LL;
LL a[N][N],dp[N][N];//从[1,1]走到[i,j]时，所有情况下的最大权值
int n;
LL f[N];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            cin >> a[i][j];
        }
    }
    //用二维数组的版本
    // for(int i = 1; i <= n;i++){
    //     for(int j = 1; j <= i;j++){
    //         dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
    //     }
    // }

    //空间优化
    for(int i = 1;i <= n;i++){
        for(int j = i;j >= 1;j--){
            f[j] = max(f[j],f[j-1]) + a[i][j];
        }
    }
    LL ret = 0;
    for(int i = 1; i <= n;i++){
        ret=max(ret,f[i]);
    }
    cout << ret <<endl;

    return 0;
}