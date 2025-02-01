#include <bits/stdc++.h>
using namespace std;

#define MAX 20000002
int m,n;
long long a[MAX];
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin>> a[i];
    }
int b[m];
    for(int i=1;i<=n;i++){
        if(i==1) {
            cout << 0;
            puts("");
        }
        else if(i<=m){
            for(int j=1;j<i;j++){
                b[j-1]=a[j];
            }
            sort(b,b+i);
            cout << b[0];
            puts("");
        }
        else if(i>m){
            int l=1;
            for(int k=i-m;k<i;k++){
                b[l-1]=a[k];
                l++;
            }
            sort(b,b+m);
            cout<<b[0];
            puts("");
        }
    }
    return 0;
}