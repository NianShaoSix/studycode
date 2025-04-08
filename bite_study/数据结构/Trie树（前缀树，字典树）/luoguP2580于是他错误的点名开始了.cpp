//https://www.luogu.com.cn/problem/P2580
#include <iostream>

using namespace std;
const int N = 5e5 + 10;
int t[N][26],e[N];
int id;
int n,m;
void insert(string &s){
    int cur = 0;
    for(char ch:s){
        int path = ch - 'a';
        if(t[cur][path] == 0) t[cur][path] = ++id;
        cur = t[cur][path];
    }
    e[cur]++;
}

int find(string &s){
    int cur = 0;
    for(auto x: s){
        int path = x - 'a';
        if(t[cur][path] == 0) return 0;
        cur = t[cur][path];
    }
    if(e[cur] > 0){
        int t = e[cur];
        e[cur] = -1;
        return t;
    }
    return e[cur];
}

int main(){
    cin >> n;
    while(n--){
        string s;cin >>s;
        insert(s);
    }
    cin >> m;
    while(m--){
        string s; cin>>s;
        int ret = find(s);
        if(ret==0) cout <<"WRONG\n";
        else if(ret==1) cout <<"OK\n";
        else cout <<"REPEAT\n";
    }
    return 0;
}