#include <iostream>
#include <cmath>
using namespace std;
int x,n;
double f(int x,int n){
    if(x==1) return sqrt(1+x);
    return sqrt(f(x,n-1));
}
int main(){
    cin >> x >>n;
    double res = f(x,n);
    printf("%.2lf",res);
    return 0;
}