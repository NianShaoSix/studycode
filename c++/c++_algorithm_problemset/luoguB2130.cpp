#include <iostream>
#include <string>
using namespace std;
int a,b;
char c;
int calc(int &a,char &c,int &b){
    switch(c){
        case '+':
        return a+b;
        case '-':
        return a-b;
        case '/':
        return a/b;
        case '*':
        return a*b;
        case '%':
        return a%b;
    }
}

int main(){
    
    cin >> a >> c >> b;
    cout <<calc(a,c,b)<<endl;
    return 0;
}