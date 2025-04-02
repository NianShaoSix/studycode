#include <iostream>

using namespace std;

int day = 6;
int a = 20,b= 22;
int ret;
void cal(){
    while(b){
        if(b&1){
            ret=(ret+a)%7;
        }   
        a=a*a%7;
        b>>=1;
    }
    ret=(ret+day)%7;
}

int main(){

    if(ret == 0) cout <<"7";
    else cout <<ret;
    return 0;

}