//用链式前向星存储树 dfs
#include <iostream>
using namespace std;
const int N = 1e5;
int n,id;
int h[N],e[2*N],ne[2*N];
bool st[N];
void add(int a,int b){
    e[++id] = b;
    ne[id] = h[a];
    h[a] = id;
}

void dfs(int u){
    cout<<u<<" ";
    st[N] = true;
    for(int i = h[u];i;i = ne[i]){
        int v = e[i];//孩子
        if(!st[v]){
            dfs(v);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int a,b;
        cin >> a >>b;
        add(a,b);
        add(b,a);
    }

    return 0;
}