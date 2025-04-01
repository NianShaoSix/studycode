//https://www.luogu.com.cn/problem/P1012
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std; 
const int N = 25;
string s[N];
bool cmp(string &x,string &y){
    return x + y > y + x;
}
int main(){
    int n;cin >>n;
    for(int i = 1;i<=n;i++){
        cin >> s[i];
    }
    //排序
    sort(s+1,s+1+n,cmp);
    for(int i = 1;i <= n;i++){
        cout << s[i];
    }
    return 0;
}