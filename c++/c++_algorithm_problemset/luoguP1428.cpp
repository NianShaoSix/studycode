#include <iostream>
using namespace std;
int  n;
int arr[110];
int count[110];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= i;j++){
            if(arr[j]<arr[i]){
                count[i]++;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout << count[i] << " ";
    }
    return 0;
}