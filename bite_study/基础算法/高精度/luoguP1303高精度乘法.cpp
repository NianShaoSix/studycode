#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N],b[N],c[N];

int la,lb,lc;

void mul(int c[],int a[],int b[]){
	//1.�޽�λ�˷� 
	for(int i = 0;i < la;i++){
		for(int j = 0;j < lb;j++){
			c[i+j] += a[i] * b[j];
		}
	}
	//2.�����λ
	for(int i = 0;i < lc;i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;	
	} 
	//����ǰ���� 
	while(c[lc-1]==0 && lc > 1) lc--;
}
int main(){
	string x,y;cin >> x >> y;
	//1.���ÿһλ���������������
	la = x.size();lb = y.size();lc = la+lb;
	for(int i = 0;i < la; i++) a[la - i - 1] = x[i] - '0'; 
	for(int i = 0;i < lb; i++) b[lb - i - 1] = y[i] - '0';
	
	//2.ģ��˷�
	mul(c,a,b);//���� c= a*b;
	
	//������
	for(int i = lc - 1;i >= 0;i--){
		cout <<c[i];
	} 
	return 0;
}
