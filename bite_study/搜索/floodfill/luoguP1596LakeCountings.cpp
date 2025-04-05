//https://www.luogu.com.cn/problem/P1596
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
const int N = 110;
char a[N][N];
bool st[N][N];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
void dfs(int i,int j){
    st[i][j] = true;
    for(int k = 0;k < 8;k++){
        int x = i + dx[k], y = j + dy[k];
        if(x >= 1&x <=n&&y >= 1&&y <=m&&a[x][y]=='W'&&st[x][y]==false){
            dfs(x,y);
        }
    }
}

void bfs(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    st[i][j] = true;

    while(q.size())
    {
        auto t = q.front();q.pop();
        int i = t.first, j = t.second;
        for(int k = 0;k < 8;k++){
            int x = i + dx[k], y = j + dy[k];
            if(x >= 1&x <=n&&y >= 1&&y <=m&&a[x][y]=='W'&&st[x][y]==false){
                st[x][y] =true;
                q.push({x,y});
            }
        }
    }
}

int main(){
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1; j<= m;j++){
            cin >> a[i][j];
        }
    }
    int ret = 0;
    
    for(int i = 1; i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j]=='W'&&st[i][j] ==false){
                ret++;
                // dfs(i,j);
                bfs(i,j);
            }
        }
    }
    cout << ret <<endl;
    return 0;
}