#include <iostream>
#include <cmath>
using namespace std;
int n;int cnt;
bool check(int x){
    for(int i = 2;i <=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i = 2;i <= n;i++){
        if(check(i)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}