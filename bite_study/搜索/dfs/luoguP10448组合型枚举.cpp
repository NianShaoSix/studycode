//https://www.luogu.com.cn/problem/P10448
#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> path;
void dfs(int begin){
    if(path.size()==m){
        for(int x:path){
            cout <<x<<" ";
        }
        cout <<endl;
        return;
    }
    for(int i = begin;i <= n;i++){
        path.push_back(i);
        dfs(i+1);
        path.pop_back();
    }
}


int main(){
    cin >> n >> m;
    dfs(1);
    return 0;
}