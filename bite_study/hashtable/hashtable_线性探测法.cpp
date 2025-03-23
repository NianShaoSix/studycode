#include<iostream>
#include <cstring>
using namespace std;

const int N = 23,INF = 0x3f3f3f3f;
int h[N];//哈希表
int n;
void init(){
    memset(h,INF,sizeof(h));
}

//哈希函数-->计算x的存储位置
int f(int x){
    int id = (x % N + N) % N;
    while(h[id]!=INF&&h[id] != x){
        id++;
        if(id == N){
            id = 0;//如果走到尾部，从头开始
        }
    } 
    return id;
}

//添加元素 
void insert(int x){
    int id = f(x);
    h[id] = x;
}
//查找操作
bool find(int x){
    int id = f(x);
    return h[id]==x;
}
int main(){
    init();
    cin >> n;
    while(n--){
        int op,x;
            cin >> op >>x;
        if(op==1){
            
            insert(x);
        }
        else{
            if(find(x)){
                cout << "yes"<<endl;
            }
            else cout << "no"<<endl;
        }
    }
    return 0;
}