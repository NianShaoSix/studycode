#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int N = 1e6 + 10;
int  gender[N];
int n;
int pre[N],ne[N];//双向列表
int flag[N];//标记是否出列
int s[N];//舞者实力
string s1;
//绑定的舞伴
struct node{
    int d,l,r;//d为实力差，l,r分别为左右舞者的编号
    bool operator < (const node &x)const{
        //先比较两队舞者的实力差值，差大的下沉
        //若相等则再比较靠左的舞者编号
        //若还是相等则比较右舞者的编号
        if(d != x.d) return d > x.d;
        else if(l !=x.l) return l > x.l;
        else if(r != x.r) return r > x.r;
    }
};
//舞者队堆
priority_queue<node> heap;

int main(){
    cin >> n;
    for(int i = 1;i <= n ; i++){
        char ch;cin >> ch;
        if(ch == 'B') gender[i] = 1;
    }
    for(int i = 1;i <= n;i++){
        cin >> s[i];  
        ne[i] = i+1;//建立双向链表
        pre[i] = i-1;
    }
    
    pre[1] = ne[n] = 0;//第一个没有前驱最后一个没有后驱

    //建堆
    for(int i = 2;i <= n; i++){
        if(gender[i]!=gender[i-1]){
            heap.push({abs(s[i]-s[i-1]),i-1,i});
        }
    }
    //舞伴出列
    vector<node> res;//存放先后的舞者
    while(heap.size()){
        node t = heap.top();heap.pop();
        int l = t.l; int r = t.r;
        if(flag[l]||flag[r]) continue;
        res.push_back(t);
        flag[l] = flag[r] = 1;
        //更新队列
        ne[pre[l]] = ne[r];
        pre[ne[r]] = pre[l];
        //添加新满足条件的舞者
       int left = pre[l]; int right = ne[r];
         if(s[left] && s[right] && gender[left]!=gender[right]){
            heap.push({abs(s[left]-s[right]),left,right});
         }
    }
    cout << res.size() <<endl;
        for(auto &e : res){
            cout << e.l << " " << e.r<<endl;
        }
    

    return 0;
}