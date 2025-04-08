//https://www.luogu.com.cn/problem/P10471
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int t[N*32][2];
int a[N];
int n,id;

void insert(int x){
    int cur = 0;
    for(int i = 31;i >= 0;i--){
        int path = ((x>>i)&1);
        if(t[cur][path] == 0) t[cur][path] = ++id;
        cur = t[cur][path];
    }
}

int find(int x){
    int cur = 0;
    int res = 0;
    for(int i = 31; i >=0;i--){
        int path = ((x>>i)&1);
        if(t[cur][path^1]){
            
            res|=(1<<i);
            cur = t[cur][path^1];
        } 
        else cur = t[cur][path];
        
    }
    return res;
}

int main(){
    cin >> n;
   for(int i = 1;i <= n;i++) {
    cin >> a[i];
    insert(a[i]);
   }
   int ret = 0;
   for(int i = 1;i <= n;i++){
    ret = max(ret,find(a[i]));
   }
   cout << ret <<endl;
    return 0;
}