//用vector数组存储树 bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n;vector<int> edges[N];
queue<int> q;
bool st[N];

void bfs(){
    q.push(1);
    st[1] = true;
    while(q.size()){
        int t = q.front();
        cout << t <<" ";
        q.pop();
        for(auto x:edges[t]){
            if(!st[x])
            q.push(x);
            st[x] = true;
        }
    }
}


int main(){
    cin >> n;
    for(int i = 1;i < n; i++){
        int a ,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    return 0;
}