#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> PII;
queue<PII> q;

const int N = 1e5 + 10;
int cnt[N];
int kinds;
int main(){
    int n;
    cin >> n;
    while (n--){
        int t,num;
        cin >> t >> num;
        for(int i  = 1;i <= num;i++){
            int x;
            cin >> x;
            q.push({t,x});
            if(cnt[x]++==0) kinds++;
        }
        if(q.size()&&q.back().first - q.front().first >= 86400){
            int tem = q.front().second;
            q.pop();
            if(cnt[tem]--==1) kinds--;
        }
        cout << kinds<<endl;
    }
    return 0;
}