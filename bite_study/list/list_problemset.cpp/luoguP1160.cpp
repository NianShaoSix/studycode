#include <iostream>
using namespace std;
const int N = 1e5+10;
int ne[N]={1,0},h,id = 1;int mp[N] = {0,1};
int pre[N];
int n,m;
int x,y,z;
int main(){
    cin >> n;
   for(int i = 2;i <= n;i++){
        cin >> x >> y;
        if(y){
            mp[i] = i;
            ne[i] = ne[x];
            pre[i] = x;
            pre[ne[x]] = i;
            ne[x] = i;
            
        }
        else {
            mp[i] = i;
            pre[i] = pre[x];
            ne[i] = x;
            ne[pre[i]] = i;
            pre[x] = i;
        }
   }
   cin >> m;
   while(m--){
    cin >> z;
    if(mp[z]){
        int p = mp[z];
        pre[ne[p]] = pre[p];
        ne[pre[p]] = ne[p];
        mp[z] = 0;
    }
   }
   for(int i = ne[h];i;i = ne[i]){
    cout << i <<' ' ;
   }
   return 0;
}