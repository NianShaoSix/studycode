#include <bits/stdc++.h>

using namespace std;
#define MAX 10000000 
int a[MAX],b[MAX];//加数和被加数
int c[MAX];//储存两加数的和，也可不用
char s1[MAX],s2[MAX];//储存两个加数的字符串
int max(int x,int y){
    return x > y ? x : y;
}
int main() {
  int len1,len2;//计算两个加数的位数
  cin >> s1;
  cin >> s2;
  len1 = strlen(s1);len2 = strlen(s2);
  int m = max(len1,len2);
  int k = 0;

  //将两个加数的每一位存到数组里,反着存，将个位存放到第一位
  for(int i = len1-1;i >= 0;i--){
        a[k++] = s1[i] - '0';
  }
  k = 0;
  for(int i = len2 - 1;i >= 0;i--){
        b[k++] = s2[i] - '0';
  }

  //高精度加法，本位加法，考虑进位
  for(int i = 0;i < m;i++){
    c[i] = c[i]+ a[i] + b[i];
    if(c[i] > 9 ) {
        c[i]%=10;c[i+1]++;
        if(i==m-1)m++;
        }
  }
  //输出结果 注意反向输出
  for(int i = m-1;i >= 0;i--) {
    if(c[m-1]==0) ;
    cout << c[i];
  }
  return 0;
} 