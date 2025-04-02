//https://www.luogu.com.cn/problem/P1036
#include <iostream>
using namespace std;
int n,k;
const int N = 21;
int a[N];long long ret;
int cnt;

bool isprime(long long x)
{
    if(x <= 1) return false;
    for(int i = 2;i <= x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}
void dfs(int pos,int begin){
    if(pos > k){
        if(isprime(ret)) cnt++;
        return; 
    }

    for(int i = begin;i <= n;i++){
        ret+=a[i];
        dfs(pos + 1,i + 1);
        ret-=a[i];
    }

}


int main(){
    cin >> n >> k;
    for(int i = 1;i <= n; i++){
        cin >>a[i];
    }
    dfs(1,1);
    cout << cnt <<endl;
    return 0;
}