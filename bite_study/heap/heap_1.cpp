//建堆 向上调整算法
//堆 向下调整算法
//1.找到左右孩子中权值最大的那个，如果该点的权值比最大孩子的权值小，就交换；
//2.重复1操作，直到该点比两个孩子结点的权值都大，或者换到叶子结点为止。
//默认为大根堆， 小根堆反过来找左右孩子小的那个....
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int heap[N];
int n;
void up(int child){
    int parent = child / 2;
    //当父节点存在，并且大于父节点的权值时
    while(parent >= 1 && heap[child] > heap[parent]){
        swap(heap[child],heap[parent]);
        child = parent;
        parent = child / 2;
    }
}

void down(int parent){
    int child = parent * 2;
    //如果存在孩子
    while(child <= n){
        //找大孩子
        if(child + 1 <= n&&heap[child + 1] > heap[child]) child++;
        if(heap[parent] >= heap[child]) return;

        swap(heap[parent],heap[child]);
        parent = child;
        child = parent * 2;
    }
}
//插入元素
void push(int x){
    heap[++n] = x;
    up(n);
}
//删除操作
//删除堆顶元素
void pop(){
    swap(heap[1],heap[n--]);
    down(1);//向下调整
}

//查询堆顶元素
int top(){
    return heap[1];
}

//堆的大小
int size(){
    return n;
}

int main(){ 
    //测试堆
    int a[10] = {1,43,23,10,11,2,-1,99,14,0};
    
    //将这十个数依次放入堆中
    for(int i = 0;i < 10;i++){
        push(a[i]);
    }

    while(size()){
        cout << top() << " ";
        pop();
    }

    return 0;
}