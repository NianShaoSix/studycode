#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int e[N]={0,1};
int ne[N],mp[N] = {0,1};
int n,id = 1;
int x,y,p;
int find(int x){
    return mp[x];
}
void push_back(int p,int x){
    e[++id] = x;
    mp[x] = id;
    ne[id] = ne[p];
    ne[p] = id;
}
void erase(int p){
    mp[e[ne[p]]] = 0;
    ne[p] = ne[ne[p]];
}
int main(){
    cin >> n;
    while(n--){
        int choice = 0;
        cin >> choice;
        switch(choice){
            case 1:
                cin >> x >>y;
                 p = find(x);
                push_back(p,y);
                break;
            case 2:
                cin >> x;
                if(ne[find(x)]){
                    cout << e[ne[find(x)]]<<endl;
                }
                else cout << 0 << endl;
                break;
            case 3:
                cin >> x;
                 p = find(x);
                erase(p);
                break;
        }
    }
    return 0;
}