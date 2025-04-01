#include <iostream>
#include <vector>
using namespace std;

const int N = 23;
int h[N];int id;
int e[N+1],ne[N+1];
int n;
int f(int x){
    return (x%N + N)%N;
}
//插入元素-处理哈希冲突
void insert(int x){
    int idx = f(x);
    //头插法
    e[++id] = x;
    ne[id] = h[idx];
    h[idx] = id;
}

bool find(int x){
    int idx = f(x);
    for(int i = h[idx];i;i=ne[idx]){
        if(e[i] == x){
            return true;
        }
    }
    return false;

}

int main(){
    cin >> n;
    while(n--){
        int op,x;
        cin >> op >> x;
        if(op == 1){
            insert(x);
        }
        else{
            if(find(x)){
                cout <<"yes" <<endl;
            }
            else cout <<"no"<<endl;
        }
    }

    return 0;
}