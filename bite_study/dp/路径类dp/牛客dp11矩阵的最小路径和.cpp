#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int n,m;
int f[N][N];

int main(){
    cin >> n >>m;
    //初始化
    memset(f,0x3f,sizeof f);
    f[0][1] = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1; j<= m;j++){
            int x;cin >> x;
            f[i][j] = min(f[i-1][j],f[i][j-1]) + x;
        }
    }
    cout<<f[n][m]<<endl;

    return 0;
}