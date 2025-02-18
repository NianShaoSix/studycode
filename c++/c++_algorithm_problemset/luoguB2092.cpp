#include <iostream>
using namespace std;
int N;
bool arr[5050];
int main(){
    cin >> N;
    for(int i = 1;i <=N;i++){
        arr[i] = true;
    }
    for(int i=1;i <= N;i++){
        for(int j=i;j<=N;j+=i){
            arr[j] = !arr[j];
        }
    }
    for(int i=1;i<=N;i++){
        if(!arr[i]) cout << i <<' ';
    }
    return 0;
}