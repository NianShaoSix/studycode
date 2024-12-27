#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050],b[500050];
//检查有没有被切割过
long long ans;
bool check(long long x) {
    //二分法找
   long long l=1,r=m,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(x<b[mid]) r=mid-1;
        else if(x>b[mid]) l=mid+1;
        else return true;
    }
    return false;
}
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
    sort(b+1,b+m+1);
    if(!check(a[n])) ans++;
    for(int i=1;i<n;i++){
        
        if(!check(a[i])&&check(a[i+1])) ans++;
    }
    cout << ans;
    return 0;
}