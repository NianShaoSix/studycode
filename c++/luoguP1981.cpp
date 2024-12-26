#include <bits/stdc++.h>
using namespace std;
stack<int> x;
int main() {
    int a,b;
    char c;
    cin >> a;//表达式的第一个数
    int m = 10000;
    a%=m;
    x.push(a);//将a压入栈中
    while(cin>>c>>b){
        if(c=='*'){
            a=x.top();
            x.pop();
            x.push(a*b%m);
        }
        else x.push(b);
    }
    a=0;
    while(x.size()){
        a+=x.top();
        a%=m;
        x.pop();
    }
    cout<<a<<endl;
    return 0;

}