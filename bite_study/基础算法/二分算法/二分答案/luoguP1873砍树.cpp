//https://www.luogu.com.cn/problem/P1873

#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL a[N];
LL n,m,ret;

LL cal(LL x){
    LL sum = 0;
    for(int i = 1;i <= n;i++){
        if(a[i]>= x)sum+=a[i]-x;
    }
    return sum;
}

int main(){
    cin >> n >>m;
    for(int i = 1;i <= n;i++ ){
        cin >> a[i];
    }

    LL left = 1,right = 4e5 + 10;
    while(left < right){
        LL mid = (left + right + 1)/2;
        if(cal(mid)>=m) left = mid;
        else right = mid - 1;
    }
    cout<< left <<endl;
    return 0;
}