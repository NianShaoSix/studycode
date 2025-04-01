#include <iostream>
#include <unordered_set>
using namespace std;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        unordered_set<int> mp;
        while(n--){
            int x;
            scanf("%d",&x);
            if(!mp.count(x)){
                cout <<x<<" ";
                mp.insert(x);
            }
        }
        puts("");
    }


    return 0;
}