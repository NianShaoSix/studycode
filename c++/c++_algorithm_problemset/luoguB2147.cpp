#include <iostream>
#include <cmath>
using namespace std;
double x;
int n;
double f(double x,int n){
    if(n==1) return sqrt(1+x);
    return sqrt(n+(f(x,n-1)));
}
int main(){
    cin >> x >>n;
    double res = f(x,n);
    printf("%.2lf",res);
    return 0;
}