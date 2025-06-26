#include<iostream>
using namespace std;
#include "swap.h"
//函数分文件编写
//实现两个数字进行交换
// void swap(int a, int b);
// void swap(int a,int b){
//     int  t = a;
//     a = b;
//     b = t;
// }
//1.创建.h后缀名的头文件
//2.创建.cpp后缀名的源文件
//3.在头文件中写函数的声明
//4.在源文件中写函数的定义

int main(){
    int a = 5,b = 10;
    swap(a,b);
    
    return 0;
}