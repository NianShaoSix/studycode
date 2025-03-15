#include <iostream>
#include <queue>
using namespace std;
const int N = 1010;
int m,n;
queue<int> q;
bool flag[N];
int main(){
    int cnt  = 0;
    cin >> m >> n;
    while(n--){
        int x = 0;
        cin >> x;
        if(!flag[x]){
            if(q.size()<=n)
           {
            cnt++;
            flag[x] = true;
            q.push(x);
           }
           else{
            int t = q.front();
            flag[t] = false;
            cnt++;
            flag[x] = true;
            q.push(x);
           }
        }

    }
    cout << cnt <<endl;
    return 0;
}