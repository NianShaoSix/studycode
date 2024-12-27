/*//高精度减法 bug：
//被减数大于减数 反过来无法计算
//10稍微加条件貌似可以提前判断两个数的大小
// 然后再进行计算
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000

int a[MAX],b[MAX];//被减数和减数
int c[MAX];//结果
char s1[MAX],s2[MAX];//存储被减数和减数
int max(int x,int y) {
    return x > y ? x : y;
}
int main() {
    cin >> s1>>s2;
    int len1,len2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    int m = max(len1,len2);
    int k = 0;
    for(int i = len1-1;i >= 0; i--) {
        a[k++] = s1[i] - '0';
    }
    k = 0;
    for(int i = len2-1;i >= 0; i--) {
        b[k++] = s2[i] - '0';
    }
    //作减法，注意借位
    for(int i = 0;i < m;i++) {
        c[i] = a[i] - b[i];
        if(c[i] < 0){ 
        c[i] = c[i] + 10;
        a[i+1]--;
        }
    }
    for(int i = m-1;i>=0;i--){
        if(c[m-1]==0) continue;
        cout<< c[i];
    }
    return 0;
}*/
#include <stdio.h>
#include <string.h>
char num1[102] = {0};
char num2[102] = {0};
int a[101] = {0};
int b[101] = {0};
int c[101] = {0};
int max(int x, int y)
{
    return x > y ? x : y;
}
int main()
{
    scanf("%102s", num1);
    scanf("%102s", num2);
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int k = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        a[k++] = num1[i] - '0';
    }
    k = 0;
    for (int i = len2 - 1; i >= 0; i--)
    {
        b[k++] = num2[i] - '0';
    }
    int cnt = max(len1, len2);
    for (int i = 0; i < cnt; i++)
    {
        c[i] = a[i] - b[i];
        if (c[i] < 0)
        {
            a[i + 1]--;
            c[i] += 10;
        }
    }
    if(c[cnt-1]==0)//用于判断相减之后首位是否是0，若首位是0，那么则不用输出
    {
        for (int i = cnt - 2; i >= 0; i--)
        {
            printf("%d", c[i]);
        }
    }
    else
    {
        for (int i = cnt - 1; i >= 0; i--)
        {
            printf("%d", c[i]);
        }
    }
    return 0;
}