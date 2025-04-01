//宽度优先遍历二叉树
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e6 + 10;
int n;
int l[N],r[N];

queue<int> q;

void bfs(){
    q.push(1);
    while(q.size()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        if(l[u])
        q.push(l[u]);
        if(r[u])
        q.push(r[u]);
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> l[i] >> r[i];
    }
    bfs();
    return 0;
}