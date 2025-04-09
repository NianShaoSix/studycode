//https://www.luogu.com.cn/problem/P1192
#include <iostream>

using namespace std;
const int N = 1e5 + 10,P = 100003;
int n,k;
int  dp[N];

int main(){
    cin >> n >>k;
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        if(i < k){
            for(int j = 0;j < i;j++){
                dp[i]=(dp[i]+dp[j])%P;
            }
        }
        else{
            for(int j = i - k;j <= i-1;j++){
                dp[i]=(dp[i]+dp[j])%P;
            }
        }
    }
    cout <<dp[n]<<endl;
    return 0;
}