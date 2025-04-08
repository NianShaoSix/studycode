//https://www.luogu.com.cn/problem/P3370
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e4 + 10;
const int p = 131;
int n;
ULL a[N];

ULL gethash(string &s){
    int t = 0;
    for(int i = 0; i<s.size();i++){
        t = t * p + s[i];
    }
    return t;
}


int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        string s;cin >> s;
        a[i] = gethash(s);
    }
    sort(a+1,a+1+n);
    int ret = 1;
    for(int i = 2;i <= n;i++){
        if(a[i]!=a[i-1]) ret++;
    }
    cout << ret <<endl;
    return 0;
}