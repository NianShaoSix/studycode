#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int a[110],b[30];
int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        
        for(int j = 0;j < m;j++){
            cin >> b[j];
        }
        sort(b,b+m);
        for(int k = 1;k < m-1;k++){
            a[i]+=b[k];
        }
    }
    sort(a,a+n);
    printf("%.2lf",a[n-1]*1.0/(m-2));
    return 0;
}