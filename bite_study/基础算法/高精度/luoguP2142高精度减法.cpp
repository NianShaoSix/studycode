#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std; 

const int N = 1e6 + 10;
int a[N],b[N],c[N];

int la,lb,lc;

//�ȴ�С 
bool cmp(string &x,string &y){
	//�ȱȽϳ���
	if(x.size()!= y.size()) return x.size() < y.size();
	//�ٰ����ֵ���ķ�ʽ�Ƚ� 
	return x < y; 
}

//�߾��ȼ�����ģ�� c = a - b; 

void sub(int c[],int a[],int b[]){
	for(int i = 0;i < lc;i++){
		c[i] +=a[i] - b[i];//��Ӧλ�����Ȼ�����λ 
		if(c[i]<0){
			c[i+1]--;//��λ 
			c[i]+=10;
		} 
	}
	while(!c[lc-1]&&lc > 1) lc--;
}

int main(){
	string x,y; cin >> x >>y;
	if(cmp(x,y)){
		swap(x,y);
		cout <<'-';
	}
	la = x.size();
	lb = y.size();
	lc = max(la,lb);
	//���ÿһλ��Ȼ���������������� 
	for(int i = 0;i < la;i++) a[la - i - 1] = x[i] - '0';
	for(int i = 0;i < lb;i++) b[lb - i - 1] = y[i] - '0';
	//2. ģ������Ĺ���
	 sub(c,a,b);
	 
	 for(int i = lc - 1;i >= 0;i--) cout << c[i];
	 
	return 0;
}
