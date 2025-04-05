//https://www.luogu.com.cn/problem/P1902
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int,int>PII;
const int  N = 1010;
int n,m;
int p[N][N];
bool st[N][N];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool bfs(int mid){
     if(n==1) return true;
    memset(st,0,sizeof st);
    queue<PII> q;
    for(int j = 1;j <= m;j++){
        q.push({1,j});
        st[N][N] = 1;
    }

    while(q.size()){
        
        auto t = q.front();q.pop();
        int x = t.first,y = t.second;
        for(int k = 0;k < 4;k++){
            int a = x + dx[k],b = y + dy[k];
            if(a>=1&&a<=n&& b>=1&&b<=m&&st[a][b]!=1&&p[a][b]<=mid){
                q.push({a,b});
                st[a][b] = 1;
            }
            if(a == n) return true;
        }
        
    }
    return false;
}

int main(){
    cin >> n >> m;
    int l = 0,r = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> p[i][j];
            r = max(r,p[i][j]);
        }
    }
    while(l < r){
        int mid = (l+r)>>1;
        if(bfs(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l <<endl;
    return 0;
}