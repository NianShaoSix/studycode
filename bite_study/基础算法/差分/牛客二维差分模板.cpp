#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1100; 
LL f[N][N];

void insert(int x1,int y1,int x2,int y2,int k){
    f[x1][y1]+=k;
    f[x1][y2+1]-=k;
    f[x2+1][y1]-=k;
    f[x2+1][y2+1]+=k; 
}

int main(){
    int n,m,q;
    cin >> n>>m>>q;
    for(int i = 1;i <=n;i++){
        for(int j = 1;j <= m;j++){
            LL x;cin >>x;
            insert(i,j,i,j,x);
        }
    }
    while(q--){
        int x1,y1,x2,y2,k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        insert(x1,y1,x2,y2,k);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1; j<= m;j++){
            f[i][j] +=f[i-1][j] + f[i][j-1] - f[i-1][j-1];
            cout <<f[i][j]<<" "; 
        }
        cout <<endl;
    }
    return 0;
}