//用vector数组存储树 dfs
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n;bool st[N];//哪些点已经访问过了
vector<int> edges[N];

void dfs(int u){
    cout << u << " ";
    st[u] = true;//标记u已经遍历
    //访问所有的孩子
    for(auto v: edges[u]){
        if(!st[v]){
            dfs(v);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int a,b;
        //建树
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    return 0;
}