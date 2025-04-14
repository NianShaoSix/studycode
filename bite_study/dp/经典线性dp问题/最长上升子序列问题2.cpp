#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n,a[N],f[N],len;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n; i++){
        //处理边界情况
        if(len == 0|| a[i] > f[len]) f[++len] = a[i];
        //二分插入
        int l = 1,r = len;
        while(l < r){
            int mid = (l+r)/2;
            if(f[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }
        f[l] = a[i];
    }
    
    return 0;
}