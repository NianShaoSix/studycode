#include <bits/stdc++.h>
using namespace std;
int n,m;
bool vis[102];
int a[102];
int b[102];
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        vis[i] = false; //初始化所有人都未出来
        a[i]=i;
        b[i]=0;
    }
    vis[0]=true;
    int j=0;int k = 0;
    int count=0;
    while (count < n){
        for(int j=1;count<n;j++){//每次遍历一遍数组
              j=j%(n+1);
            if(vis[j]==false){
                k++;
            }
            if(k==m){
                vis[j]=true;
                count ++;
                b[count]=a[j];
                k=0;
            }
        }
      
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
/*#include<cstdio>
using namespace std;
int main()
{
    int n,m,s=0;scanf("%d%d",&n,&m);//入读
    bool visit[200]={0};//visit赋初始值
    for(int k=0;k<n;k++){//总共要出队n次
        for(int i=0;i<m;i++){if(++s>n)s=1;if(visit[s])i--;}//类似取模，而因为序列是从1开始的，所以不取模，加判断；若visit过，则i--，使其继续循环
        printf("%d ",s);visit[s]=true;//输出，记录已出队
    }
    return 0;
}*/