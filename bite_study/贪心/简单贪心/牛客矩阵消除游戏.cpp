//https://ac.nowcoder.com/acm/problem/200190
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20;
int a[N][N];
int col[N];
int ret;int n,m,k;
bool cmp(int&x,int&y){
    return x>y;
}
int cal(int x){
    int sum = 0;
    while(x){
        sum++;
        x&=x-1;
    }
    return sum;
}

int main(){
    cin >> n >>m >>k;
    for(int i  = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >>a[i][j];
        }
    }
    //二进制枚举列
    for(int st  = 0;st <(1<<n);st++){
        memset(col,0,sizeof col);
        if(cal(st) > k) continue;
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j <m;j++){
                if((st>>i)&1==1)   res +=a[i][j];
                else col[j] += a[i][j];
            }
        }
        sort(col,col+m,cmp);
        for(int l = 0;l < min(k-cal(st),m);l++){
            res+=col[l];
        } 
        ret=max(ret,res);
    }
    cout <<ret <<endl;
    return 0;
}