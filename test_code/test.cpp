#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int x,int y){
    return x>y;
}
int main() {
    int arr[6]={0,1,4,3,5,6};
    sort(arr+1,arr+6,compare);
    for(int i=1;i<=5;i++){
        cout << arr[i]<<' ';
    }
}