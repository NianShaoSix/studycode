//https://www.luogu.com.cn/problem/P1162
#include <iostream>
#include <cstring>
using namespace std;
const int N = 35;
int n;
int dx[]= {0,0,1,-1};
int dy[] = {1,-1,0,0};
int a[N][N];
int st[N][N];

void dfs(int i, int j){
    st[i][j] = 1;
    for(int k = 0;k < 4;k++){
        int x = i + dx[k], y = j + dy[k];
        if(x >= 0&& x <=n+1&&y >= 0&&y <= n&&a[x][y]==0&&st[x][y]==0)
        dfs(x,y);
    }
}

int main(){
     
     while(cin >> n){
        memset(st,0,sizeof st);
        for(int i = 1;i <= n;i++){
            for(int j = 1; j <= n;j++){
                cin >> a[i][j];
            }
        }
        dfs(0,0);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(st[i][j]|| a[i][j]){
                    cout <<a[i][j]<<" ";
                }
                else cout <<2<<" ";
            }
            puts("");
        }
    }
    return 0;
}