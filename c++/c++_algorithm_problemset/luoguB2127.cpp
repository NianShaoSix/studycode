#include <iostream>
#include <cmath>
using namespace std;
int n;
void wqnumber(int x){
    int sum = 1;
    for(int i = 2;i < x;i++){
        if(x%i==0)
        sum+=i;
    }
    if(sum == x)
    printf("%d\n",x);
}
int main(){
    cin >> n;
    for(int i  = 2;i <= n;i++){
        wqnumber(i);
    }
    return 0;
}