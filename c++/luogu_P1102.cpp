#include<iostream>
#include<string>
using namespace std;

typedef struct {
    int *base;
    int *top;
    int stacksize;
} SqStack;//顺序栈

int InitStack(SqStack &S){
    S.base = new int[100];
    if(!S.base) exit(-1);
    S.top = S.base;
    S.stacksize = 100;
    return 1;
}//初始化栈

bool StackEmpty(SqStack S){
    return S.top == S.base;
}//判断栈是否为空

bool StackFull(SqStack S){
    return S.top == S.base + S.stacksize;
}//判断栈是否满了

int Push(SqStack &S, int e){
    if(StackFull(S)){
        int* newbase = new int[S.stacksize + 10];
        if(!newbase) exit(-1);
        for(int i = 0; i < S.stacksize; i++){
            newbase[i] = S.base[i];
        }
        delete[] S.base;
        S.base = newbase;
        S.top = S.base + S.stacksize;
        S.stacksize += 10;
    }
    *S.top++ = e;
    return 1;
}//压栈

int Pop(SqStack &S, int &e){
    if(StackEmpty(S)) return -1;
    e = *--S.top;
    return 1;
}//出栈

int getTop(SqStack &S){
    if(StackEmpty(S)) return -1;
    return *(S.top - 1);
}//取栈顶元素

bool In(char c, char OP[]){
    for(int i = 0; i < 7; i++){
        if(c == OP[i]) return true;
    }
    return false;
}//判断字符是否在运算符集合中

char Precede(char a, char b){
    char OP[] = {'+', '-', '*', '/', '(', ')', '#'};
    char precede[7][7] = {
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=', ' '},
        {'>', '>', '>', '>', ' ', '>', '>'},
        {'<', '<', '<', '<', '<', ' ', '='}
    };//算符间的优先关系
    int i, j;
    for(i = 0; i < 7; i++){
        if(a == OP[i]) break;
    }
    for(j = 0; j < 7; j++){
        if(b == OP[j]) break;
    }
    return precede[i][j];
}//算符间的优先关系

int Operate(int a, char theta, int b){
    switch(theta){
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '*': return a * b;
    }
    return 0;
}//计算

int main(){
    char OP[7] = {'+', '-', '*', '/', '(', ')', '#'};
    SqStack OPND, OPTR;
    InitStack(OPND);
    InitStack(OPTR);
    Push(OPTR, '#');

    cout << "请输入表达式(以#表示输入结束): ";
    char c = getchar();
    while(c != '#' || getTop(OPTR) != '#'){
        if(isdigit(c)){
            int num = 0;
            while(isdigit(c)){
                num = num * 10 + (c - '0');
                c = getchar();
            }
            Push(OPND, num);
        } else if(In(c, OP)){
            switch (Precede(getTop(OPTR), c)){
                case '<':
                    Push(OPTR, c);
                    c = getchar();//读取下一个字符
                    break;
                case '=':
                    int e;
                    Pop(OPTR, e);
                    c = getchar();//忽略右括号
                    break;
                case '>':
                    int a, b, theta;
                    Pop(OPTR, theta);
                    Pop(OPND, a);
                    Pop(OPND, b);
                    Push(OPND, Operate(b, theta, a)); // 注意操作数的顺序
                    break;
            }
        } else {
            c = getchar();//忽略空格
        }
    }
    cout << "结果: " << getTop(OPND) << endl;
    return 0;
}