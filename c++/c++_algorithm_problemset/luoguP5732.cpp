#include <iostream>
using namespace std;
int arr[22][22];
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0; j <= i;j++){
            if(j == 0){
                arr[i][j] = 1;
            }
            else if(i == j){
                arr[i][j] = 1;
            }
            else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        cout << arr[i][j] << " ";
        }
        puts("");
    }
    /*for(int i = 0; i < n;i++){
        for (int j = 0;j <= i;j++){
            cout << arr[i][j] << " ";
        }
        cout <<"\n";
    }*/
    return 0;
}