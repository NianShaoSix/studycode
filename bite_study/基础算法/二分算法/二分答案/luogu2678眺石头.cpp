//https://www.luogu.com.cn/problem/P2678
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 5e4 + 10;
LL a[N];
LL l,n,m;

LL cal(LL x){
    LL sum = 0;
    for(int i = 0;i <= n;i++){
        int j = i + 1;
        while(a[j] - a[i]< x&& j <= n){
          j++;
        }
        sum+=j-i-1;
        i = j -1;
    }
    return sum;
}

int main(){
    cin >> l >> n >>m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    a[n+1] = l;
    n++;
    LL left = 1,right = l;
    while(left < right){
        LL mid = (left + right +1 )/2;
        if(cal(mid) <= m)  left = mid;
        else right = mid - 1; 
    }
    cout <<left<<endl;
    return 0;
}