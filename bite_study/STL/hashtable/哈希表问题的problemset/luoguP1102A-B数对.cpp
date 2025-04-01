#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
unordered_map<LL,LL> mp;
const int N = 2e5 + 10;
int n,c;
LL cnt;
int a[N];
int main(){
    cin >> n >> c;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i = 1;i <= n;i++){
        cnt+=mp[a[i]+c];
    }

    cout << cnt << endl;
    return 0;
}