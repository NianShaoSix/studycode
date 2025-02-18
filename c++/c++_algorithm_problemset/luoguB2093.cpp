#include <iostream>
using namespace std;
int n,m;
int main(){
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;int j = 0;
    for(int i = 0;i < n; i++){
        if(m == arr[i]){
            cout << i;
            break;
        }
        j = i;
    }
    if(j==n-1) cout << -1;
    
    return 0;
}