#include <iostream>
using namespace std;
int Akm(int m,int n){
    if(m==0){
        return n + 1;
    }
    if (n==0&&m>0){
        return Akm(m-1,1);
    }
    if(m>0&&n>0){
    return Akm(m-1,Akm(m,n-1));
}

}
int main(){
    int m,n;
    cin >> m >>n;
    int r = Akm(m,n);
    cout << r <<endl;
    return 0;
}