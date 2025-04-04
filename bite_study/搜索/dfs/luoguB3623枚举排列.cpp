//https://www.luogu.com.cn/problem/B3623
#include <iostream>
#include <vector>
using namespace std;
const int N = 15;
int n,k;
vector<int> path;
bool st[N];//标记哪些数已经选过了

void dfs()
{
    if(path.size()==k){
        for(int x:path) cout<<x<<" ";
        cout << endl;
        return ;
    }
    for(int i = 1;i <= n;i++){
        if(st[i]) continue;
        path.push_back(i);
        st[i] = true;
        dfs();
        path.pop_back();
        st[i] = false;
    }
}
int main(){
    cin >> n >>k;
    dfs();
    return 0;
}