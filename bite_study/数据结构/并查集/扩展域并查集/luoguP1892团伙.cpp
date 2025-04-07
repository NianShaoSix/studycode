//https://www.luogu.com.cn/problem/P1892
#include <iostream>

using namespace std;
const int N = 1010;
int fa[N*2];
int n,m;

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x,int y){
    fa[find(y)] = find(x);
}

bool issame(int x,int y){
    return find(x)==find(y);
}

int main(){
    cin >> n >>m;
    for(int i = 1;i <= 2*n;i++){
        fa[i] = i;
    }

    while(m--){
        char opt;
        int x,y;
        cin >> opt >> x >>y;
        if(opt=='E'){
            un(x,y + n);
            un(y,x + n);
        } 
        else un(x,y);
    }
    int ret = 0;
    for(int i = 1;i <= n;i++){
        if(fa[i]==i) ret++;
    }
    cout<< ret<<endl;
    return 0;
}