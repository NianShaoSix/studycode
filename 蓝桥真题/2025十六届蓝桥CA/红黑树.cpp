#include <bits/stdc++.h>

using namespace std;
const int N = 1e8 + 10;
int a[N];

int main(){
    a[1] = 1;
    for(int i = 2;i <= N;i++){
        if(i%2==0){
            a[i] = a[i/2];
        }
        else {
            a[i] = !a[i/2];
        }
    }
    int m;cin>>m;
    while(m--){
        int n,k;cin >>n >>k;
        int pos = 0;
        n--;
        if(n == 0) pos = k;
        else {
            pos = (1 << n) - 1 + k;
        }
        if(a[pos]) cout <<"RED"<<endl;
        else cout <<"BLACK"<<endl;
    }

    return 0;
}
