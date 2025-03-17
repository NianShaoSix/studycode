#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int n;
const int N = 110;
queue<int>q;
vector<int>edges[N];
int fa[N];

int dfs(int x){
    int res = 0;
    for(auto a: edges[x])
       res =max(res,dfs(a));
    return res + 1;
}

int  bfs(){
    q.push(1);
    int w = q.size();
    while(q.size()){
        int tem = q.size();
        w = max(w,tem);
        while(tem--){
            int t = q.front();
            q.pop();
            for(auto x:edges[t]){
                q.push(x);
            }
        }
    }

    return w;
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        //建树
        edges[u].push_back(v);
        fa[v] = u;
    }
    //求树的深度
    cout << dfs(1) <<endl;
    //求树的宽度
    cout << bfs() <<endl;
    //求x到y的距离
    int x,y; cin >> x >>y;
    int dist[N] = {0};
    while(x != 1){
        dist[fa[x]] = dist[x] + 1;
        x = fa[x];
    }
    int len = 0;
    while(y != 1 && dist[y] == 0){
        len ++;
        y = fa[y];
    }
    cout << dist[y] * 2 + len << endl;
}