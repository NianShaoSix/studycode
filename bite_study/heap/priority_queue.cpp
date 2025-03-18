//stl提供的堆优先级队列
#include <iostream>
#include <vector>
#include <queue>//priority_queue的头文件
using namespace std;

int a[10] = {1, 41, 23, 10, 11, 2, -1, 99, 14, 0};

struct node{
    int a,b,c;
    //重载 < 运算符
    //这里按照b为基准创建大根堆
    // bool operator < (const node&x) const
    // {
    //     return b < x.b;
    // }
    bool operator < (const node&x) const
    {
        return b > x.b;
    }


};

void test(){
    priority_queue<node> heap;
    for(int i = 1;i <= 5; i++){
        heap.push({i+5,i+1,i+2});
    }
    while(!heap.empty()){
        node t = heap.top();heap.pop();
        cout << t.a <<" " << t.b <<" " <<t.c<<endl;
    }
}


int main(){
    // priority_queue<int,vector<int>,greater<int>>heap;//默认是一个大根堆
    // for(int i = 0;i < 10;i++){
    //     heap.push(a[i]);
    // }
    // while(heap.size()){
    //     cout << heap.top() << " ";
    //     heap.pop();
    // }
    test();


    return 0;
}