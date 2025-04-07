//https://www.luogu.com.cn/problem/P2024
#include <iostream>

using namespace std;

const int N = 5e4 + 10;

int a[N];
int fa[N * 3];
int n,k;

int find(int x){
    return fa[x] == x?x:fa[x]=find(fa[x]);
}

void un(int x ,int y ){
    fa[find(x)] = find(y);
}

bool issame(int x,int y){
    return find(x)==find(y);
}

int main(){
    cin >> n >>k;
    for(int i = 1;i <= 3*n;i++){
        fa[i] = i;
    }
    int ret = 0;
    while(k--){
        int op,x,y;cin >> op >> x >> y;
        if(x > n||y > n) ret++;
        else if (op == 1){
            if(find(x) == find(y + n)||find(x)==find(y + 2*n)){
                ret++;
            }
            else{
                un(x,y);un(x+n,y+n);un(x+2*n,y+2*n);
            }
        }
        else{
            if(issame(x,y)||find(x)==find(y + n)) ret++;
            else{
                un(x,y+n+n);un(y,x+n);un(x+n+n,y+n);
            }
        }
    }
    cout << ret <<endl;
    return 0;
}