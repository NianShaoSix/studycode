//https://www.luogu.com.cn/problem/P1443
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int,int> PII;
const int N = 410;
int n,m,x,y;
int f[N][N];
queue<PII> q;
int dx[] = {1,-1,2,-2,1,-1,2,-2};
int dy[] = {2,2,-1,-1,-2,-2,1,1};

void bfs(){

    memset(f,-1,sizeof f);
    f[x][y] = 0;
    q.push({x,y});
    while(q.size()){
        auto t = q.front();q.pop();
        for(int i = 0;i < 8;i++){
            
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x < 1||x > n||y<1||y>m) continue;
            if(f[x][y]!=-1) continue;
            f[x][y] = f[t.first][t.second] + 1;
            q.push({x,y});
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            printf("%-5d",f[i][j]);
        }
        cout << endl;
    }

}

int main(){

    cin >> n >>m >> x>>y;
    bfs();
    return 0;
}