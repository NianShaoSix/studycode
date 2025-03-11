#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c;
double m;
int Max(int x,int y,int z){
    // int max = 0;
    // if(x>=y&&x>=z) return x;
    // else if(y>=x&&y>=z) return y;
    // else return z;
    // int max = x > y?x:y;
    // return max > z ?max : z;
    int m = max(x,y);
    return max(m,z);
}
int main(){
    cin >> a >> b >> c;
    m = Max(a,b,c)*1.0/(Max(a+b,b,c)*Max(a,b,b+c));
    printf("%.3f",m);
    return 0;
}