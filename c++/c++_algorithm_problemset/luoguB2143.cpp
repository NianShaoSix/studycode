#include <iostream>
#include <string>
using namespace std;
string s ="0123456789ABCDEF";
void x_to_m(int x,int m){
    if(x>=m)
        x_to_m(x/m,m);

    cout <<s[x%m];
}
int main(){
    int x,m;
    cin >> x >> m;
    x_to_m(x,m);
    return 0;
}