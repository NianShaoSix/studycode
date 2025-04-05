//https://www.luogu.com.cn/problem/P1588
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int t;
int dist[N];
int n = 1e5;
void bfs(int x,int y){
    memset(dist,-1,sizeof dist);
    queue<int> q;
    int res = 1e5+10;
    dist[x] = 0;q.push(x);
    while(q.size()){
        int j = q.front();q.pop();
        int a = j + 1,b = j - 1,c = 2*j;
        if(a <= n&&dist[a]==-1){
            dist[a] = dist[j]+1;
            q.push(a);
        }
        if(b > 0&&dist[b]==-1){
            dist[b] = dist[j] + 1;
            q.push(b);
        }
        if(c <= n&&dist[c]==-1){
            dist[c] = dist[j] + 1;
            q.push(c);
        }
        if(a==y||b==y||c==y) return;
    }
}


int main(){
    cin >> t;
    while(t--){
      int x,y;
      cin >> x >>y;
      bfs(x,y);
      cout <<dist[y]<<endl;  
    }
    return 0;
}