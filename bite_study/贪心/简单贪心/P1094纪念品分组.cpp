//https://www.luogu.com.cn/problem/P1094
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e4 + 10;
int a[N];
int main(){
    int w,n;cin >> w>>n;
    for(int i = 1;i <= n;i++){
        cin >> a[i]; 
    }
    sort(a+1,a+n+1);
    int left = 1, right = n, ret = 0;
    while(left <= right){
        if(a[left]+a[right] <= w) left++,right--;
        else right--;
        ret++;
    }
    cout << ret <<endl;
    return 0;
}