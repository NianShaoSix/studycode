//https://www.luogu.com.cn/problem/P1219
#include <iostream>
#include <vector>
using namespace std;
const int N = 15;
int col[N],st1[N * 2],st2[N*2];
int n,ret;
vector<int>path;
void dfs(int x){
    if(x > n){
        ret++;
        if(ret <= 3){
            for(int e: path){
                cout <<e<<" ";
            }
            cout << endl;
        }
        return ;
    }
    for(int y = 1;y <= n;y++){
        if(col[y]||st1[y-x+n]||st2[y+x]) continue;
        path.push_back(y);
        col[y] = st1[y - x + n] = st2[y + x] = 1;
        dfs(x + 1);
        path.pop_back();
        col[y] = st1[y - x + n] = st2[y + x] = 0;
    }

}


int main(){
    cin >> n;
    dfs(1);
    cout << ret <<endl;
    return 0;
}