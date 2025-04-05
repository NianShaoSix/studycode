//https://www.luogu.com.cn/problem/P1379
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
string s;
string aim = "123804765";
unordered_map<string,int> dist;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(){
    queue<string> q;
    q.push(s);
    dist[s] = 0;

    while(q.size()){
        string t = q.front();q.pop();
        int pos = 0;
        while(t[pos]!='0') pos++;
        int x = pos/3;int y = pos%3;
        for(int i = 0;i < 4;i++){
            
            int a = x +dx[i],b = y +dy[i];
            if(a>=0&&a<=2&&b>=0&&b<=2){
                string next = t;
                int p = 3*a+b;
                swap(next[p],next[pos]);
                if(dist.count(next)) continue;
                dist[next] = dist[t] + 1;
                q.push(next);

                if(next == aim) return ;
            }
        }
    }

}

int main(){

    cin >> s;
    bfs();
    cout <<dist[aim]<<endl;
    return 0;
}