//https://www.luogu.com.cn/problem/P1596
#include <iostream>

using namespace std;
const int N = 110;
char a[N][N];
int fa[N*N];
int n,m;
int dx[]={0,1,1,1};
int dy[] ={1,-1,0,1};
int find(int x){
    return fa[x]==x?x:fa[x] = find(fa[x]);
}
void un(int x,int y){
    int a = find(x),b = find(y);
    fa[b] = a;
}
int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j<m;j++){
            cin >> a[i][j];
            int pos = i*m+j;
            fa[pos] = pos;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(a[i][j]=='.') continue;
            int pos = i*m+j;
            for(int k = 0;k<4;k++){
                int x = i + dx[k], y = j + dy[k];
                if(y >= 0&&a[x][y] == 'W'){
                    un(pos,x*m+y);
                }
            }
        }
    }
    int ret = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(a[i][j]=='W'&&fa[i*m+j]==i*m+j){
                ret++;
            }
        }
    }
    cout << ret <<endl;
    return 0;
}