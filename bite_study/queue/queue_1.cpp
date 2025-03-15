#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
int main(){
    queue<PII> q;

    for(int i = 1;i <= 10;i++){
        q.push({i,i*10});
    }
    while(q.size()){
        auto t = q.front();
        q.pop();
        cout<<t.first<<" " <<t.second << endl;
        
    }

    return 0;
}