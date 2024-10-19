#include<iostream>
using namespace std;

typedef struct {
    int *base;//栈底指针:在栈构造之前和销毁之后，base的值为NULL
    int *top;//栈顶指针:指向栈顶元素的下一个位置
    int stacksize;//栈的大小
}SqStack;//顺序栈

//初始化栈
int InitStack(SqStack &S){
   S.base= new int[100];//申请100个int类型的空间
    if(!S.base) exit(-1);//申请失败
    S.top=S.base;//栈顶指针指向栈底
    S.stacksize=100; //栈的大小为100
    return 1;
}

//判断栈是否为空
bool StackEmpty(SqStack S){
  return S.top==S.base;
}
//判断栈是否满了
bool StackFull(SqStack S){
   return S.top==S.base+S.stacksize;
}
//压栈
int Push(SqStack &S,int e){
   
 
}
int main(){

    return 0;
}