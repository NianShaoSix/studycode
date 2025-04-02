//https://www.luogu.com.cn/problem/P9241
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int N = 15;
int T,n;
int t[N],d[N],l[N];
int st[N];
bool dfs(int pos,int end){
    if(pos > n){
        return true;
    }
    for(int i = 1;i <= n;i++){
        if(st[i]) continue;
        if( t[i] + d[i] < end)  continue;
        int newend = max(end,t[i]) + l[i];
        st[i] = 1;
        if(dfs(pos + 1,newend)){
            return true;
        }
        st[i] = 0;//恢复现场
    }
    return false;
}

int main(){
    cin >> T;
    while(T--){
        memset(t,0,sizeof t);
        memset(d,0,sizeof d);
        memset(l,0,sizeof l);
        memset(st,0,sizeof st);
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >>t[i]>>d[i]>>l[i];
        }
        if(dfs(1,0)) cout <<"YES"<<endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}