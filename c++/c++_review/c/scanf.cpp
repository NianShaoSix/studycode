#include<cstdio>
#include<iostream>
using namespace std;
int main() {
    int n = 0;
    //scanf("%d", &n);
   // printf("%d", n);
    //char ch;
    //scanf("%c",&ch);//%c占位符不会忽略空格
    //printf("%c\n",ch);
    //scanf返回值 正确读入时返回读入的个数
    //错误读取返回0
    //一个都不输入ctrl+z 也就是EOF 返回-1
    int b,c;
    int a = scanf("%d%d%d",&n,&b,&c);
    printf("%d",a);
    return 0;
}