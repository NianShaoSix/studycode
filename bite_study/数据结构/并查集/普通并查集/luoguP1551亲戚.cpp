//https://www.luogu.com.cn/problem/P1551
#include <iostream>

using namespace std;
const int N = 5010;
int fa[N];

int  find(int x){
    return fa[x] == x?x:fa[x] = find(fa[x]);
}

void un(int x,int y){
    fa[find(x)] = find(y);
}

bool issame(int x,int y){
    return find(x)==find(y);
}

int main(){
    int m,n,p;cin >> m >> n >>p;
    for(int i = 1;i <= m;i++) fa[i] = i;
    while(n--){
        int x,y;cin >> x>>y;
        un(x,y);
    }
    while(p--){
        int x,y;cin >> x >>y;
        if(issame(x,y)){
            cout<<"Yes\n";
        }
        else cout <<"No\n";
    }
    return 0;
}