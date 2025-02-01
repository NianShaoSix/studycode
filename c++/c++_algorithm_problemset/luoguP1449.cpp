#include <bits/stdc++.h>
using namespace std;

char s[52];
long long arr[52];
int i=0,now=0;
int main() {
    char ch;
    while((ch=getchar())!='@'){
        if(ch>='0'&&ch<='9'){
            now*=10;now+=ch-'0';
        }
        else if(ch=='.'){
            arr[++i]=now;
            now=0;
        }
        else if(ch=='+'){
            arr[i-1]=arr[i-1]+arr[i];
            arr[i]=0;
            i--;
        }
        else if(ch=='-'){
             arr[i-1]=arr[i-1]-arr[i];
            arr[i]=0;
            i--;
        }
        else if(ch=='*'){
             arr[i-1]=arr[i-1]*arr[i];
             arr[i]=0;
             i--;
        }
        else if(ch=='/'){
             arr[i-1]=arr[i-1]/arr[i];
             arr[i]=0;
             i--;
        }
    }
    cout<<arr[1];    
}