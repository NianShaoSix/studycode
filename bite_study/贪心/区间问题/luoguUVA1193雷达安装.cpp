//https://www.luogu.com.cn/problem/UVA1193
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1010;

int n;double d;



struct node{
    double left,right;
}a[N];

bool cmp(const node&x,const node&y){
    return x.left<y.left;
}

int main(){
    int cnt = 0;
    while(cin >> n >> d,n&&d){
        cnt++;
        bool flag = false;
        for(int i = 1;i <= n;i++){
            double x,y;cin >> x>>y;
            if(y > d) flag = true;
            double l = sqrt(d*d - y*y);
            a[i].left = x - l,a[i].right = x + l;
        }
        if(flag) cout <<"Case "<<cnt<<": -1"<<endl;
        else{
            sort(a+1,a+1+n,cmp);
            double r = a[1].right;int ret = 1;
            for(int i = 2;i <= n;i++){
                if(a[i].left <= r){
                    r = min(r,a[i].right);
                }
                else{
                    ret++;
                    r = a[i].right;
                }
            }
            cout <<"Case "<<cnt<<": "<<ret<<endl;
        }
    }
    return 0;
}