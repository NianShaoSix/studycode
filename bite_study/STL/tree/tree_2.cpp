#include <iostream>
using namespace std;
const int N = 1e5+10;
int n;int id;
//链式前向星
int h[N],e[2*N],ne[2*N];
int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int a = 0, b = 0;
        cin >> a >> b;
        e[++id] = b;
        ne[id] = h[a];
        h[a] = id;
        e[++id] = a;
        ne[id] = h[b];
        h[b] = id;
    }
    return 0;
}