#include <iostream>
using namespace std;
const int N = 1e6 + 10;//具体大小以实际题目而定
int a[N];//用足够大的数组模拟顺序表的实现
int n;

//打印顺序表
void print_Sq(){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    puts("");
}

//尾插法--->直接添加
void push_back(int x){
    //判断是否满了
    a[++n] = x;
}

//头插法--->添加前先移动空出表头
void push_front(int x){
    //判断是否满了
    for(int i=n;i>=1;i--){
        a[i+1]=a[i];
    }
    a[1]=x;
    n++;
}

//在任意位置插入
void insert(int p,int x) {
    //判断插入位置是否合法

    //判断是否满了
    for(int i=n;i>=p;i--){
        a[i+1]=a[i];
    }
    a[p]=x;
    n++;
}

//删除最后一个元素
void pop_back(){
    //删除前检查顺序表是否为空
    n--;
}
//删除表头的元素
void pop_front(){
    //删除前检查顺序表是否为空
    for(int i=1;i<=n-1;i++){
        a[i]=a[i+1];
    }
    n--;
}
//删除任意位置的元素
void erase(int q){
    //删除前检查顺序表中是否有元素
    //删除位置是否合法
    for(int i=q;i<=n-1;i++){
        a[i]=a[i+1];
    }
    n--;
}
//查找一个数 找到就返回下表 没找到返回-1
int find(int x){
    for(int i=1;i<=n;i++) {
        if(a[i]==x) return i;
    }
    return -1;
}
//按位查找
int find_Sq(int q){
    //检查查找位置是否合法
    return a[q];
}//顺序表的特性 随机存取

//修改元素 按位修改
void change(int p,int x) {
    //位置p要合法
    a[p]=x;
}

//清空顺序表
void clear(){//粗略的
    n = 0;
}

int main() {
    push_back(2);
    push_back(5);
    push_back(1);
    push_back(3);
    print_Sq();
    push_front(10);
    print_Sq();
    insert(3,0);
    print_Sq();
    pop_back();
    print_Sq();
    pop_front();
    print_Sq();
    erase(2);
    print_Sq();
    cout<<find(2)<<"\n";
    cout<<find(1)<<"\n";
}