#include<iostream>
#include<String>
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
    if(StackEmpty(S)) {//判断栈是否满了
    int* newbase=new int[S.stacksize+10];  //重新分配空间
    if(!newbase) exit(-1);//分配失败
    for(int i=0;i<S.stacksize;i++){
        newbase[i]=S.base[i];
        }//将原来的数据复制到新的空间
        delete[] S.base;//释放原来的空间
    S.base=newbase;//新的栈底指针
    S.top=S.base+S.stacksize;//新的栈顶指针
    S.stacksize+=10;//新的栈的大小
    }else{
        *S.top++=e;//栈顶指针指向的位置赋值为e
    }   
    return 1;
}

//出栈
int Pop(SqStack &S,int &e){
    if(StackEmpty(S)) return -1;//判断栈是否为空
    else{
        e=*--S.top;
        delete S.top;
    }//不为空则将栈顶元素赋值给e并释放栈顶元素
    return 1;
}


int main(){
    cout<<"请输入表达式";//读取运算表达式
    String s;
    cin.get(s,'\n');
    //创建操作数栈和操作符栈
    //遍历操作符栈 判断操作符的先后顺序 弹出操作数栈的两个元素进行运算 运算结果压栈 直到操作符栈为空
    //最后输出操作数栈的栈顶元素
    return 0;
}