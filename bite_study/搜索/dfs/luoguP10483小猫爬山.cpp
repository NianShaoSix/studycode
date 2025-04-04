//https://www.luogu.com.cn/problem/P10483
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 18;
int a[N],s[N];
int n,w;
int ret = N;
int cnt = 1;
bool cmp(const int&x, const int&y){
    return x>y;
}

void dfs(int pos){
   if(cnt >= ret) return;

   if(pos > n){
    ret = cnt;
    return;
   }

   for(int i = 1; i <= cnt;i++){
    if(s[i] + a[pos] > w) continue;
    s[i] +=a[pos];
    dfs(pos+1);
    s[i]-=a[pos];
   }
   cnt++;
   s[cnt] = a[pos];
   dfs(pos + 1);
   s[cnt] = 0;
   cnt--;
}


int main(){
    cin >> n >> w;
    
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    sort(a+1,a+1+n,cmp);

    dfs(1);

    cout << ret;

    return 0;
}