#include <iostream>
using namespace std;
int arr[110][110];
int m,n;
int cnt;
int main(){
    
    cin >> m >>n;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            int x;
            cin >> x;
            if(x == arr[i][j])cnt++;
        }
    }
    printf("%.2f",cnt*1.0*100/(m*n));
    return 0;
}