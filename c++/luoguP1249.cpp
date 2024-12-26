/*#include <bits/stdc++.h>
using namespace std;
int n,sum=0,i=0;
long long ex=1;
long long a[100000];
int main() {
    cin >> n;
    if(n<=4) {cout<<n-1<<'\n'<<n-1;return 0;}
    for(i=2;sum<n;i++){
        sum+=i;
        a[i]=i;
    }
    if(sum==n){
        for(int j=2;j<i;j++){
            cout<<a[j]<<' ';
            ex*=a[j];
        }
        puts("");
        cout<<ex;
    }
    else if(sum - n==1){
        
        a[i-1]+=1;
        for(int j=3;j<i-1;j++){
            cout<<a[j]<<' ';
            ex*=a[j];
        }
        puts("");
        cout<<ex;
    }
    else if(sum - n>1){
        for(int j=2;j<i;j++) {
            if(a[j]==sum-n){
                a[j]=0;
            }
        }
        for(int j=2;j<i;j++){
            if(a[j]!=0){cout<<a[j]<<' ';
            ex*=a[j];}
        }

        puts("");
        cout<<ex;
    }
    
    return 0;
}*/
//错误解答 因为最后的最大乘积很大用longlong也储存不下，所有改用字符串储存大数


//下面是正确解法

#include <bits/stdc++.h>
using namespace std;
int n;//输入的数
int i,sum=0;
char s1[1000];char s2[1000];//s1为分解的组合 s2为s1乘积的各位
int sa1[1000];
char res[10000];//存放结果
void mutiple(char a[], char b[]){

}

int main() {
    cin >> n;
    //特殊情况
    if(n==1||n==2||n==3||n==4){
        cout << n;
        puts("");
        cout << n;
        return;
    }
    //拆解
    for(i = 2;sum<n;i++){
        sum+=i;
        s1[i]=(char)+'0';
    }
    //如果sum比n大1 则将s1[2]--;
    if(sum - n == 1) {s1[2]=;s1[2]=(char)}
    else if(sum - n > 1 )
}


