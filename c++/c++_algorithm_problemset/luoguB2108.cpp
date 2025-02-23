#include <iostream>
#include <cmath>
using namespace std;
int arr[110][110];
int b[110][110];
int main(){
    int m,n;
    cin >> m >>n;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j<= n;j++){
            cin >> arr[i][j];
            b[i][j] = arr[i][j];
        }
    }
    for(int i = 2;i <= m-1;i++){
        for(int j = 2;j <= n-1;j++){
            b[i][j] = round((arr[i-1][j] + arr[i][j-1] + arr[i+1][j] + arr[i][j+1] + arr[i][j])/5.0);
             //b[i][j] = (int)((arr[i-1][j] + arr[i][j-1] + arr[i+1][j] + arr[i][j+1] + arr[i][j])/5.0 + 0.5);
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
           cout << b[i][j] << " ";
        }
        puts("");
    }
    return 0;
}