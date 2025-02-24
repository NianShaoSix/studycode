#include<iostream>
#include <cstring>
#include <cctype>
using namespace std;
char arr[110];
int main() {
    //cin >> arr;
    //int len = strlen(arr);
    //for(int i = 0;i < len;i++){
    //    if(arr[i] >= 'a' && arr[i] <= 'z'){
    //        arr[i] -= 32;
    //    }
    //}
    //cout << arr <<endl;
    //return 0;
    cin >> arr;
    int len = strlen(arr);
    for(int i = 0; i < len;i++){
        if(islower(arr[i])){
            arr[i] = toupper(arr[i]);
        }
    }
    cout << arr <<endl;
    return 0;
}