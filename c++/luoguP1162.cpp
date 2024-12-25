#include <bits/stdc++.h>
using namespace std;
int n;
int arr1[32][32];//原始地图
int arr2[32][32];//涂色后的地图
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};
void dfs(int i, int j) {
    if (i<0||i>n+1||j<0||j>n+1||arr2[i][j]!=0) return ;
    arr2[i][j] = 1;//涂色
    for(int k = 1;k <= 4;k++) {
    dfs(i+dx[k],j+dy[k]);
    }
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr1[i][j];
            if(arr1[i][j]==0) arr2[i][j]=0;
            else arr2[i][j]=1;
        }
    }
    dfs(0,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(arr2[i][j]==0)
                cout<<2<<' ';
            else cout<<arr1[i][j]<<' ';
        puts("");
    }
    return 0;
}
