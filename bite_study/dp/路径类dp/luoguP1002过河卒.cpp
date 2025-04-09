//https://www.luogu.com.cn/problem/P1002
#include <iostream>
#include <cmath>
using namespace std;
const int N = 25;
typedef long long LL;
LL f[N][N];
int n,m,a,b;
bool check(int i,int j){
    if((a!=i&&b!=j&&abs(i-a)+abs(j-b)==3)||a==i&&b==j){
        return false;
    }
    return true;
}

int main(){
    
    cin >> n >>m>>a>>b;
    n++,m++,a++,b++;
    f[1][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(check(i,j)) f[i][j] = f[i-1][j] + f[i][j-1];
            else continue;
        }
    }

    cout <<f[n][m]<<endl;
    return 0;
}