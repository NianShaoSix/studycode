//https://www.luogu.com.cn/problem/P10468
#include <iostream>

using namespace std;
typedef unsigned long long ULL;
const int N = 1e6 + 10,P = 131;
ULL a[N],p[N];

int main(){
    string s;cin >> s;
    p[1] = 1;
    for(int i = 1;i <= s.size();i++){
        a[i] = a[i - 1] * P + s[i - 1];
        p[i+1] = p[i] * P;
    }
    int n;cin >> n;
    while(n--){
        int l1,r1,l2,r2;cin >> l1>>r1>>l2>>r2;
        ULL t1 = a[r1] - a[l1] * p[r1-l1+1];
        ULL t2 = a[r2] - a[l2] * p[r2-l2+1];
        if(t1 == t2){
            cout << "Yes\n";
        }
        else cout <<"No\n" ;
    }
    return 0;
}