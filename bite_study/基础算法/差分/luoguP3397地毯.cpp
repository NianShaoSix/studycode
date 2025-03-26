#include <iostream>

using namespace std;

const int N = 1100;
int f[N][N];
void insert(int x1,int y1,int x2,int y2){
    f[x1][y1]++;
    f[x1][y2+1]--;
    f[x2+1][y1]--;
    f[x2+1][y2+1]++;
}



int n,m;
int main(){
    cin >> n >>m;
    for(int j = 1;j <= m;j++){
        int x1,y1,x2,y2;
        cin >> x1 >>y1 >>x2 >>y2;
        insert(x1,y1,x2,y2);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
            cout <<f[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}

