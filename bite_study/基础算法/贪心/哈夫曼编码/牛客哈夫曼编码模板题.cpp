#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
priority_queue<LL,vector<LL>,greater<LL>> q; 
int n;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        LL x;cin>>x;
        q.push(x);
    }
    LL ret = 0;

    while(q.size()>1){
        LL x = q.top();q.pop();
        LL y = q.top();q.pop();
        ret+=x+y;
        q.push(x+y);
    }
    cout << ret << endl;
    return 0;
}