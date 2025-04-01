#include <iostream>
#include <vector>
using namespace std;
const int  N = 1e5+10;
int n,q;


int main() {
    vector<int>vec[N];
    cin >> n >> q;
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            int a,b,c;
            cin >> a >> b >>c;
            if(vec[a].size()<=b)
            vec[a].resize(b+1);
             
            vec[a][b]=c;
        }
        if(x==2){
            int a,b;
            cin >> a >> b;
            cout << vec[a][b];
            puts("");
        }
    }
    return 0;
}