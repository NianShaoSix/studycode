//https://www.luogu.com.cn/problem/P1901
#include <iostream>
#include <stack>

using namespace std;
const int N = 1e6 + 10;
int n;
int a[N],w[N],f1[N],f2[N];
int res[N];
void f(){

    stack<int>st1;
    stack<int>st2;
    for(int i = 1;i <= n;i++)
    {
        while(st1.size()&&a[st1.top()]<=a[i])st1.pop();
        if(st1.size()) f1[i] = st1.top();
        st1.push(i);
    }
    for(int i = n;i >= 1;i--){
        while(st2.size()&&a[st2.top()]<=a[i])st2.pop();
        if(st2.size()) f2[i] = st2.top();
        st2.push(i);
    }

}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >>a[i]>>w[i];
    }
    f();
    int ret = 0;
    for(int i = 1; i <= n;i++){
        res[f1[i]] += w[i];
        res[f2[i]] += w[i];
    }

    for(int i = 1;i <= n;i++){
        ret=max(ret,res[i]);
    }

    cout <<ret <<endl;
    return 0;
}