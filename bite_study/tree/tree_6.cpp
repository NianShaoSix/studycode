//链式前向星存储树 bfs
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n;bool st[N];queue<int> q;
int id,h[N],e[N*2],ne[N*2];

void add(int a,int b){
    e[++id] = b;
    ne[id] = h[a];
    h[a] = id;
}

void bfs(){
    q.push(1);
    st[1] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        cout << u <<" ";
        for(int i = h[u];i;i = ne[i]){
            int v = e[i];
            if(!st[v]){
                q.push(v);
                st[v] = true;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >>b;
        add(a,b);
        add(b,a);
    }
    bfs();
    return 0;
}