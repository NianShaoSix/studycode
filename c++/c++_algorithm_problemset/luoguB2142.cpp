#include <iostream>
using namespace std;
int n;
int cal(int x){
    if(x == 1) return 1;
    return x+cal(x-1);
}
int main(){
    cin >> n;
    int r = cal(n);
    cout <<r;
    return 0;
}