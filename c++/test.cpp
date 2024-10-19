#include<iostream>
using namespace std;
int main(){
    char arr[100];
    cin>>arr;
    int count=0;
    for(int i=0;i<100;i++){
        if(arr[i]==' '&&arr[i+1]!=' '){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
    
}