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
int way[N]; //����һ������ way�����ڴ洢��ǰ����Ϸ���
 
void dfs(int u, int start){  //u ��ʾ��ǰ�����λ�ã�start ��ʾ��ǰ��ѡ���ֵ���ʼλ��
   //�����ж������ǰλ�� u ���� m + 1�����ʾ�Ѿ�ѡ���� m �����֣���ʱ�����ǰ��Ϸ�������������һ��ݹ顣
    if(u == m + 1){  //����֮�����ж������� u == m + 1 ������ u == m������Ϊ����������Ǵ� 1 ��ʼ�ģ������Ǵ� 0 ��ʼ��
        for(int i=1;i<=m;i++) printf("%d ",way[i]);
        puts("");//�൱�ڻس�����
        return;
    }
    for(int i=start;i<=n;i++){
        way[u]=i;
        dfs(u+1,i+1);
        way[u]=0;//�ָ��ֳ�
    }
}
 
int main(){
    scanf("%d%d",&n,&m);
    dfs(1,1);
    
    return 0;
}
