#include <iostream>
#include <cstring>
using namespace std;
char arr[110];
char b[110];
int main(){
    cin >> arr;
    int len = strlen(arr);
    for(int i = 0;i< len -1 ;i++){
        b[i] = arr[i]+arr[i+1];
    }
    b[len-1] = arr[len - 1] + arr[0]; 
    cout << b << endl;
    return 0;
}