#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char arr[300];
int main(){
    int cnt = 0;
    //fgets(arr,255,stdin);
    scanf("%[^\n]s",arr);
    int len = strlen(arr);
    for(int i = 0;i <len;i++) {
        //if(arr[i]>='0'&&arr[i]<='9'){
        //    cnt ++;
        //}
        if(isdigit(arr[i])){
            cnt++;
        }
    }
    cout << cnt <<endl;
    return 0;
}