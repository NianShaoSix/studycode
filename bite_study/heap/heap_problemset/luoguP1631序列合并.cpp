#include<iostream>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 1e5 +10;
LL a[N],b[N];
int n;

struct node{
    LL s,i,j;
    bool operator <(const node& x)const{
        return s > x.s; 
    } 
};

LL calculate(int i,int j){
    return a[i] + b[j];
}


priority_queue<node>heap;
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    } 
    for(int i = 1;i <= n;i++){
        cin >> b[i];
    } 
    //将所有的第一个值放入堆中
    for(int i = 1;i <= n;i++){
        heap.push({calculate(i,1),i,1});
    }
    //依次计算n个
    while(n--){
        auto t = heap.top();heap.pop();
        LL s = t.s; LL i = t.i; LL j = t.j;
        cout <<s<<" ";
        heap.push({calculate(i,j+1),i,j+1});
    }
    return 0;
}