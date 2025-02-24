#include <iostream>
#include <cstring>
using namespace std;
char arr1[21];
char arr2[21];
int main(){
    cin >> arr1;
    cin >> arr2;
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if(len1>=len2){
        if(strstr(arr1,arr2)){
            cout << arr2 <<" is substring of "<<arr1<<endl;
        }
        else cout << "No substring" << endl;
    }
    else{
        if(strstr(arr2,arr1)){
            cout << arr1 <<" is substring of "<<arr2<<endl;
        }
        else cout << "No substring" << endl;
    }
    return 0;
}
