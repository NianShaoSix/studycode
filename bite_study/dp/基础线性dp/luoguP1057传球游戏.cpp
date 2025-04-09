//https://www.luogu.com.cn/problem/P1057
#include <iostream>

using namespace std;

const int N = 35;
int n,m;
int f[N][N];//传递了i次传到了j手里的方案数
int main(){

    cin >> n >>m;
    f[0][1] = 1;
    for(int i = 1; i<= m;i++){
        //第一位同学的情况
        f[i][1] = f[i-1][n] + f[i-1][2];
        //中间的同学
        for(int j = 2;j < n;j++){
        f[i][j] = f[i-1][j-1] + f[i-1][j+1];
        }
        //第n号同学
        f[i][n] = f[i-1][n-1] + f[i-1][1];
    }
    cout <<f[m][1]<<endl;
    return 0;
}