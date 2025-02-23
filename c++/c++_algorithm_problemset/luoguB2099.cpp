#include <iostream>
using namespace std;
int arr[6][6];
int main(){
    int a,b;
    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++){
            cin >> arr[i][j];
        }
    }
    cin >> a >> b;
    for(int i = 1;i <= 5;i++){
        int temp = arr[a][i];
        arr[a][i] = arr[b][i];
        arr[b][i] = temp;
    }
    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++){
            cout << arr[i][j] <<" ";
        }
    puts("");
    }
    return 0;
}