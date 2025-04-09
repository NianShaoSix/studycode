//https://www.luogu.com.cn/problem/P1541
#include <iostream>

using namespace std;
const int N = 360,M = 50;
int n,m;
int x[N];
int cnt[5];
int dp[M][M][M][M];
int main(){
    cin  >> n >> m;

    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int i = 1;i <= m;i++) {
        int e;cin >>e;
        cnt[e]++;
    }
    dp[0][0][0][0] = x[1];

    for(int a = 0;a <= cnt[1];a++)
        for(int b = 0;b <= cnt[2];b++)
            for(int c = 0;c <= cnt[3];c++)
                for(int d = 0;d <= cnt[4];d++){
                    int &t = dp[a][b][c][d];
                    int path = 1+a+b*2+c*3+d*4;
                    if(a) t = max(t,dp[a-1][b][c][d]+x[path]);
                    if(b) t = max(t,dp[a][b-1][c][d]+x[path]);
                    if(c) t = max(t,dp[a][b][c-1][d]+x[path]);
                    if(d) t = max(t,dp[a][b][c][d-1]+x[path]);
                }
    cout <<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]<<endl;
    return 0;
}