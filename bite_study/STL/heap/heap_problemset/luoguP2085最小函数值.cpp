#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 1e4 + 10;
LL n,m;
LL a[N],b[N],c[N];

struct node{
    LL f;//函数值
    LL num;//第几个函数
    LL x;//x的值
    //建一个小根堆
    bool operator <(const node &x)const{
           return  f > x.f;
    }
};

priority_queue<node> heap;

LL calculate(LL i,LL x){
    return a[i]*x*x+b[i]*x+c[i];
}

int main(){
    cin >> n >> m;
    //把系数存入
    for(int i = 1;i <= n;i++){
        cin >>a[i]>>b[i]>>c[i];
    }
    //将x=1先存进小根堆中
    for(int i = 1;i <= n;i++){
        heap.push({calculate(i,1),i,1});
    }
    //2.依次拿出m个值
    while(m--){
        auto t = heap.top();heap.pop();
        LL f = t.f;LL num = t.num;LL x = t.x;
        cout<<f<<" ";
        //把下一个函数值放入堆中
        heap.push({calculate(num,x+1),num,x+1});
    }

    return 0;
}