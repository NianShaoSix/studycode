#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char arr[] = "hello world";
    cout << arr << endl;

    memset(arr + 2, 'x',5);
    cout << arr <<endl;
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {1};
    memcpy(arr2,arr1,10*sizeof(int));
    for(auto e: arr2){
        cout << e << endl;
    }
    return 0;
}