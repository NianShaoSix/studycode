#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], h, id;
int mp[N];
//头插
void push_front(int x){
    id++;
    e[id] = x;
    mp[x] = id;//标记 x 存储的位置
    ne[id] = ne[h];
    ne[h] = id;
}
//遍历链表
void print(){
    for(int i = ne[h];i;i = ne[i]){
        cout << e[i] <<" ";
    }
    cout << endl <<endl;
}
//按值查找
int find(int x){
    // for(int i = ne[h];i;i = ne[i]){
    //     if(e[i] == x){
    //         return i;
    //     }
    // }
    return mp[x];
}
// 在任意位置之后插入元素
void insert(int p,int x){
    id++;
    e[id] = x;
    mp[x] = id;
    ne[id] = ne[p];
    ne[p] = id;
}
//删除任意位置之后的元素
void del(int p){
    if(ne[p]){
        mp[e[ne[p]]] = 0;
        ne[p] = ne[ne[p]];
    }
}


int main(){
     for(int i = 1; i <= 5; i++){
        push_front(i);
        print();
     }
    //  cout << find(1) << endl;
    //  cout << find(5) << endl;
    // insert(1,50);
    // print();
    // insert(2,100);
    // print();
     return 0;
}