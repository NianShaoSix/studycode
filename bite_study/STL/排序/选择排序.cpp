#include <iostream>
using namespace std;
const int N = 1e5+10;
int n;
int arr[N];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    for(int i = 1;i <= n;i++){//代排区间的首位置
        //[i,n]待排区间
        int pos = i;
        for(int j = i+1;j <= n;j++){
            if(arr[j] < arr[pos]) pos = j;
        }
        swap(arr[i],arr[pos]);
    }
    for(int i = 1;i <=n;i++){
        cout << arr[i] <<" ";
    }
    return 0;
}