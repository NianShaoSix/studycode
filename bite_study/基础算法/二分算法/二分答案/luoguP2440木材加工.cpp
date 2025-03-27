//https://www.luogu.com.cn/problem/P2440
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL a[N];
LL n,k;
LL cal(LL x){
    int sum = 0;
    for(int i = 1;i <=n ;i++){
        sum+=a[i]/x;
    }
    return sum;
}
int main(){
    
    cin >> n >>k;
    LL Max = 0;
    for(int i = 1;i <= n;i++){
        
        cin >> a[i];
        Max = max(Max,a[i]); 
    }
    int left = 0,right = Max;
    while(left < right){
        LL mid =left +(right - left + 1)/2;
        if(cal(mid) >= k) left = mid;
        else right = mid - 1;
    }
    cout <<left<<endl;
    return 0;
}