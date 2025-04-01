#include <iostream>
using namespace std;
const int N = 1e5+10;
int n;
int arr[N];
int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i]; 
    }
    for(int i = 2;i<=n;i++){
        int tem = arr[i];
        for(int j = i-1;j >=1;j--){
            if(arr[j]>tem){
                arr[j+1] = arr[j]; 
                arr[j] = tem;
            }
            else break;
        }

    }
    for(int i = 1;i <= n;i++){
        cout << arr[i] <<" ";
    }
    return 0;
}