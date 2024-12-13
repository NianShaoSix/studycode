/*#include<iostream>
using namespace std;
int arr[25];
void print_one_result(int m){
	for(int i=0;i<m;i++){
		if(i) cout<<" ";
		cout<<arr[i];
	}
	cout << endl;
	return ;
} 

void f(int i, int j, int n, int m){
		if(i==m) {
		print_one_result(m);
		return ;}
		for(int k=j;k<=n&&n-k>=m-1-i;k++){
			arr[i]=k;
			f(i+1, k+1, n, m);
			arr[i]=0;
		}
		return ;
	
}

int main(){
	int n,m;
	cin >> n >> m;
	f(0,1,n,m);	
	return 0;
}*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
 
using namespace std;
 
const int N=30;
 
int n,m;   
int way[N]; //定义一个数组 way，用于存储当前的组合方案
 
void dfs(int u, int start){  //u 表示当前处理的位置，start 表示当前可选数字的起始位置
   //首先判断如果当前位置 u 等于 m + 1，则表示已经选择了 m 个数字，此时输出当前组合方案，并返回上一层递归。
    if(u == m + 1){  //这里之所以判断条件是 u == m + 1 而不是 u == m，是因为数组的索引是从 1 开始的，而不是从 0 开始。
        for(int i=1;i<=m;i++) printf("%d ",way[i]);
        puts("");//相当于回车作用
        return;
    }
    for(int i=start;i<=n;i++){
        way[u]=i;
        dfs(u+1,i+1);
        way[u]=0;//恢复现场
    }
}
 
int main(){
    scanf("%d%d",&n,&m);
    dfs(1,1);
    
    return 0;
}
