//https://www.luogu.com.cn/problem/P4554
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;
typedef pair<int,int> PII;
const int N = 510;
int n,m;
int x1,y1,x2,y2;
char arr[N][N];
int dist[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(){
    if(x1 == x2 && y1 == y2){
        dist[x2][y2] = 0;
        return ;
    }
    deque<PII> q;
    memset(dist,-1,sizeof dist);
    dist[x1][y1] = 0;
    q.push_back({x1,y1});
    while(q.size())
    {
        auto t = q.front();q.pop_front();
        int i = t.first,j = t.second;
        if(i == x2 && j == y2) return;
        for(int k = 0;k < 4;k++){
            int a = i + dx[k], b = j + dy[k];
            if(a >= 0&& a< n&&b >= 0&&b<m){
                int w = (arr[i][j]== arr[a][b]?0:1);
                
                if(dist[a][b]==-1){
                    if(w == 0) q.push_front({a,b});
                    else q.push_back({a,b});
                    dist[a][b] = dist[i][j] + w;
                }
                else if(dist[i][j]+w<dist[a][b]){
                    dist[a][b] = dist[i][j] + w;
                }
            }
        }
    }

}
int main(){
    while(cin >> n >> m,n&&m){

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >>arr[i][j];
            }
        }

        cin >> x1 >> y1 >> x2 >> y2;
        bfs();
        cout << dist[x2][y2]<<endl;
    }
    

    return 0;
}