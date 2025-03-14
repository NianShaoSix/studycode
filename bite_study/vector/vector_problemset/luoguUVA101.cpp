#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
const int N = 30;
vector<int> p[N];
typedef pair<int,int> PII;
PII find(int x){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p[i].size();j++){
            if(x == p[i][j])
                return {i,j};
        }
    }
}
void clear(int x,int y){
    for(int i = y + 1;i < p[x].size();i++){
        p[p[x][i]].push_back(p[x][i]);
    }
    p[x].resize(y + 1);
}
void move(int x,int y,int z){
    for(int i = y;i < p[x].size();i++){
        p[z].push_back(p[x][i]); 
    }
    p[x].resize(y);
}
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        p[i].push_back(i);
    }
    string op1,op2;
    int a,b;
    while(cin >> op1 >> a >> op2 >> b){
        PII pa = find(a);
        int x1 = pa.first,y1 = pa.second;
        PII pb = find(b);
        int x2 = pb.first,y2 = pb.second;
        if(x1 == x2) continue;

        if(op1 == "move"){
            clear(x1,y1);
        }
        if(op2 == "onto"){
            clear(x2,y2);
        }
        move(x1,y1,x2);
    }
    
    for(int i = 0;i < n;i++){
        cout << i <<":";
        for(int j = 0;j < p[i].size();j++){
            cout << " " << p[i][j];
        }
        cout << '\n';
    }
    return 0;
}