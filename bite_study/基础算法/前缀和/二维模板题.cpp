#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1100;
LL a[N][N],f[N][N];
LL n,m,q;
LL x1,y1,x2,y2;
LL ret;

int main(){
    cin >> n >> m>>q;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            f[i][j] = f[i-1][j] + f[i][j-1] -f[i-1][j-1] +a[i][j]; 
        }
    }
  
    while(q--){
        cin >>x1>>y1>>x2>>y2;
        ret = f[x2][y2] - f[x1-1][y2] -f[x2][y1-1] + f[x1-1][y1-1];
        cout << ret <<endl;
    }
    return 0;
}