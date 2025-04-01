//https://www.luogu.com.cn/problem/P1803
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int n;
struct node{
    int left,right;
}a[N];
bool cmp(const node &x,const node &y){
    return x.left < y.left;
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >>a[i].left>>a[i].right;
    }
    sort(a+1,a+1+n,cmp);
    int r = a[1].right,ret = 1;
    for(int i = 2;i <= n;i++){
        if(a[i].left < r){
            r = min(r,a[i].right);
        } 
        else{
            ret++;
            r = a[i].right;
        }
    }
    cout << ret <<endl;
    return 0;
}