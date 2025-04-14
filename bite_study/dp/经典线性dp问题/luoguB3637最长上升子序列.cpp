//https://www.luogu.com.cn/problem/B3637
#include <iostream>

using namespace std;

const int N = 5010;
int a[N];
int dp[N];
int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >>a[i];

    for(int i = 1;i <= n;i++) dp[i] = 1;

    int ret = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j < i;j++){
            
            if(a[j] < a[i]) dp[i] = max(dp[i],dp[j]+1);

            ret = max(ret,dp[i]);
        }
    }   
    cout << ret <<endl;
    return 0;
}