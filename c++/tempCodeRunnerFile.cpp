#include <bits/stdc++.h>
using namespace std;
int n,sum=0,i=0;
long long ex=1;
long long a[100000];
int main() {
    cin >> n;
    if(n<=4) {cout<<n<<'\n'<<n;return 0;}
    for(i=2;sum<n;i++){
        sum+=i;
        a[i]=i;
    }
    if(sum==n){
        for(int j=2;j<i;j++){
            cout<<a[j]<<' ';
            ex*=a[j];
        }
        puts("");
        cout<<ex;
    }
    else if(sum - n==1){
        a[i-3]=a[i-3]+a[i-1]/2;
        a[i-2]=a[i-2]+a[i-1]/2;
        a[i-1]=0;
        for(int j=2;j<i-1;j++){
            cout<<a[j]<<' ';
            ex*=a[j];
        }
        puts("");
        cout<<ex;
    }
    else if(sum - n>1){
        for(int j=2;j<i;j++) {
            if(a[j]==sum-n){
                a[j]=0;
            }
        }
        for(int j=2;j<i;j++){
            if(a[j]!=0){cout<<a[j]<<' ';
            ex*=a[j];}
        }

        puts("");
        cout<<ex;
    }
    
    return 0;
}