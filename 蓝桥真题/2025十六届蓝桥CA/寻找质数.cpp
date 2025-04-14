#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
long long ret;
bool isprime(LL x){
    for(int i = 2; i <= sqrt(x);i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    LL i = 1;    
    while(ret < 2025){
        i++;
        if(isprime(i)){
            ret++;
        }
        
    }
    cout << i;

    return 0;
}