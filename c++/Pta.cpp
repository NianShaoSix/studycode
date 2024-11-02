#include<iostream>
using namespace std;
int main(){
    int a,b;int n=0,res=0;
    cin>>a>>b;
    if(a%2==0){
        n=(b-a+1)/2;
        res=n*(a+1)+n*(n-1);
        cout<<res;
    }
    else {
        n=(b-a+1)/2+1;
        res=n*a+n*(n-1);
        cout<<res;
    }
}
