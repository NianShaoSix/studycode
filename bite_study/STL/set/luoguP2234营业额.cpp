#include <iostream>
#include <set>
using namespace std;
int n,res;
const int INF = 1e7;
set<int> mp;
int main(){
    cin >> n;
    int x;                                    
    cin >> x;
    res = x;
    mp.insert(x);
    mp.insert(-INF);
    mp.insert(INF);
    for(int i = 2;i <= n;i++)          
    {
        cin >> x;
        auto right = mp.lower_bound(x);
        auto left = right;
        left--;
        mp.insert(x);
        if(*right == x) continue;
        res += min(abs(x - *left),abs(x - *right));
    }
    cout << res << endl;
    return 0;
}