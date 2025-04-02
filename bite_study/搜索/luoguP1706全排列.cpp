//https://www.luogu.com.cn/problem/P1706
#include <iostream>
#include <vector>
using namespace std;
const int N = 10;
int n;
bool st[N];
vector<int>path;
void dfs(){
    if(path.size()==n){
        for(int x:path)cout<<"    "<<x;
        cout << endl;
    }
    for(int i = 1;i <= n;i++){
        if(st[i])continue;
        path.push_back(i);
        st[i] = true;
        dfs();
        path.pop_back();
        st[i] = false;
    }
}

int main(){

    cin >> n;
    dfs();
    return 0;
}