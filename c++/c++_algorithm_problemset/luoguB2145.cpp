#include <iostream>
using namespace std;
int digit(int n,int k){
    // int res = 0;
    // for(int i = 0;i < k;i++){
    //     res = n%10;
    //     n/=10;
    // }
    // return res;
    if(k==1) return n%10; 
    return digit(n/10,k-1);
}
int main(){
    int n,k;
    cin >> n >>k;
    int r = digit(n,k);
    cout << r <<endl;
    return 0;
}