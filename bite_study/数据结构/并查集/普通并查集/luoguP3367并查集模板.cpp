//https://www.luogu.com.cn/problem/P3367
#include <iostream>

using namespace std;
const int N = 2e5 + 10;
int n,m;
int fa[N];

int find(int x){
    return fa[x] == x?x:fa[x] = find(fa[x]);
}

void un(int x, int y){
    int a = find(x),b = find(y);
    fa[a] = b;
}

bool issame(int x,int y){
    return find(x)==find(y);
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    while(m--){
        int z,x,y;cin >> z >> x >> y;
        if(z == 1){
            un(x,y);
        }
        else {
            if(issame(x,y)){
                cout << "Y\n";
            }
            else cout <<"N\n";
        }
    }
    return 0;
}