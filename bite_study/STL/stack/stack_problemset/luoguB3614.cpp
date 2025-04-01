#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 10;
 typedef unsigned long long LL;
unsigned long long st[N];
int t,n;int sz;
string op;
void push(LL x){
    st[++sz] = x;
}
int size(){
    return sz;
}
void pop(){
    sz--;
}

LL query(){
    return st[sz];
}

int main(){
    cin >> t;
    while(t--){
        sz = 0;
        cin >> n;
        while(n--){
            cin >> op;
            if(op == "push"){
                LL x;
                cin >> x;
                push(x);
            }
            if(op == "pop"){
                if(sz){
                    pop();
                }
                else cout <<"Empty"<<endl;
            }
            if(op == "query"){
                if(sz){
                    cout << query() << endl; 
                }
                else cout <<"Anguei!"<<endl;
            }
            if(op == "size"){
                cout <<size()<<endl;
            }
        }
    }

    return 0;
}