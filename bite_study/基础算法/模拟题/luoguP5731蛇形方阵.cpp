#include<iostream>
using namespace std;
const int N = 10;
int n;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int arr[N][N];
int pos;
int main(){
	cin >> n;
	//ģ���������� 
	int x = 1,y = 1;
	int cnt = 1;//��ǰλ��Ҫ����� 
	while(cnt <= n * n){
		int a,b;
		arr[x][y] = cnt;
		//���㷽�� 
		a = x + dx[pos];
		b = y + dy[pos];
		//�ж�Խ�磬Խ�绻��һ������ 
		if(a < 1 ||b < 1 ||a > n || b > n||arr[a][b] != 0){
			pos = (pos + 1)%4;
			a = x + dx[pos], b = y + dy[pos];
		}
		x = a, y = b;
		cnt++;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <=n;j++)
		printf("%3d",arr[i][j]);
		puts("");
	}
	return 0;
} 
