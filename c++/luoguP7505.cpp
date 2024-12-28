#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,k;
long long b[50050];
long long vis[50050];
void move(long long a[],long long x){

    for(int i=1;i<=n;i++){
        a[i]+=x;
    }
}
void check(long long a[]){
    
    for(int i=1;i<=n;i++){
        if(a[i]<-k){
            
         vis[i]=1;
             
        }
        if(a[i]>k){
            
                vis[i]=1;
           
        }
    }
}
int main() {
    cin >> n>> m>> k;
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    sort(b+1,b+n+1);
    
    while(m--){
        int op;
        cin>>op;
    switch (op)
    {
    case 1:{
        long long x;
        cin >> x; 
        move(b,x);
        check(b);
        break;}
    
    case 2:{
        long long x=0;
        cin >> x;
        move(b,-x);
        check(b);
        break;
    }
    
    case 3:{
        long long count=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]) {count++;}
        }
        cout<<count;
        puts("");
        break;
        }
    }
    }
    return 0;
}