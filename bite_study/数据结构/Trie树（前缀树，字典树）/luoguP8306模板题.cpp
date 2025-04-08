//https://www.luogu.com.cn/problem/P8306
#include <iostream>
#include <cctype>
using namespace std;
const int N = 3e6 + 10;
int t[N][62],p[N];
int idx;

int get_num(char ch){
    if(islower(ch)) return ch - 'a';
    else if(isupper(ch)) return 26 + ch - 'A';
    else return ch - '0' + 52;
}

void insert(string &s){
    int cur = 0;
    p[cur]++;
    for(auto x: s){
        int num = get_num(x);
        if(t[cur][num]==0) t[cur][num] = ++idx;

        cur = t[cur][num];
        p[cur]++;
    }
}

int find_pre(string &s){
    int cur = 0;
    for(auto x: s){
        int num = get_num(x);
        if(t[cur][num]==0) return 0;
        cur = t[cur][num];
    }
    return p[cur];
}

int main(){
    int T;cin>>T;
    while(T--){
        for(int i = 0;i<= idx;i++){
            for(int j = 0; j < 62;j++){
                t[i][j] = 0;
            }
        }
        for(int i = 0;i <= idx;i++){
            p[i] = 0;
        }
        idx = 0;
        int n,q;cin >> n >>q;
        while(n--){
            string s;cin >> s;
            insert(s);
        }
        while(q--){
            string s;cin >>s;
            cout<<find_pre(s)<<endl;
        }
    }

    return 0;
}