//https://www.luogu.com.cn/problem/P1955
#include <iostream>
#include <unordered_map>
#include <algorithm>
//用来离散化
using namespace std;
const int N = 1e5 + 10;
int fa[N*2];
int  dist[N * 2];
unordered_map<int,int> mp;
int pos;
struct node{
    int x,y,e;
}a[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void un(int x,int y){
    fa[find(x)] = find(y); 
}

bool issame(int x,int y){
    return find(x)==find(y);
}

bool solve(){
    pos = 0;
    mp.clear();
    int n; cin >> n;
    for(int i = 1;i <= n;i++){
        cin >>a[i].x>>a[i].y>>a[i].e;
        dist[++pos] = a[i].x;
        dist[++pos] = a[i].y;
    }
    sort(dist + 1,dist+1+pos);
    //离散化
    int cnt = 0;
    for(int i = 1;i <= pos;i++){
        if(mp.count(dist[i])) continue;
        mp[dist[i]] = ++cnt;
    }
    //初始化
    for(int i = 1;i <= cnt;i++){
        fa[i] = i;
    }
    //并查集

    for(int i = 1;i <= n;i++){
        if(a[i].e == 1){
            int x = a[i].x,y = a[i].y;
            un(mp[x],mp[y]);
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i].e == 0){
            int x = a[i].x,y = a[i].y;
            if(issame(mp[x],mp[y]))
            return false;
        }
    }
    return true;
}


int main(){
    int T;cin >> T;

    while(T--){

        if(solve()){
            cout <<"YES"<<endl;
        }
        else cout << "NO"<<endl;

    }


    return 0;
}