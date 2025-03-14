#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int e[N],pre[N],ne[N];
int mp[N];//
int id,h;

//双向链表头插
void push_front(int x){
    e[++id] = x;
    mp[x] = id;
    pre[id] = h; 
    ne[id] = ne[h];
    pre[ne[h]] = id;
    ne[h] = id;
}
//遍历链表
void print(){
    for(int i = ne[h];i;i = ne[i]){
        cout << e[i] <<" ";
    }
    cout << endl;
}
//按值查找
int find(int x){
    // for(int i = ne[h];i;i = ne[i]){
    //     if(x == e[i]) return i;
    // }
    // return 0;
    return mp[x];
}

//在任意位置后插入元素
void insert_back(int p,int x){
    e[++id] = x;
    mp[x] = id;
    pre[id] = p;
    ne[id] = ne[p];
    pre[ne[p]] = id;
    ne[p] = id;
}
//在任意位置之前插入元素
void insert_front(int p, int x){
    e[++id] = x;
    mp[x] = id;
    pre[id] = pre[p];
    ne[id] = p;
    ne[pre[p]] = id;
    pre[p] = id;
}
//删除任意位置的元素
void erase(int p){
    mp[e[p]] = 0;
    ne[pre[p]] = ne[p];
    pre[ne[p]] = pre[p];
    
}

int main(){
    
    for(int i = 1;i<=5;i++){
        push_front(i);
        print();
    }
    insert_front(2,22);
    print();
    insert_front(3,33);
    print();
    insert_front(4,44);
    print();
    // cout << find(3)<<endl;
    // cout << find(5) << endl;
    // cout << find(0) << endl;
    return 0;
}