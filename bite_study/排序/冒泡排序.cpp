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
    for(int i = 1;i < n;i++){
        bool flag = false;
        for(int j = i + 1;j <= n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
                flag = true;
            }
        }
        if(!flag) break;
    }

    for(int i = 1;i <= n;i++){
        cout << arr[i] <<" ";
    }
    return 0;
}