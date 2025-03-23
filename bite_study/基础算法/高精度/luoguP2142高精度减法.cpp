#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std; 

const int N = 1e6 + 10;
int a[N],b[N],c[N];

int la,lb,lc;

//比大小 
bool cmp(string &x,string &y){
	//先比较长度
	if(x.size()!= y.size()) return x.size() < y.size();
	//再按照字典序的方式比较 
	return x < y; 
}

//高精度减法的模板 c = a - b; 

void sub(int c[],int a[],int b[]){
	for(int i = 0;i < lc;i++){
		c[i] +=a[i] - b[i];//对应位相减，然后处理借位 
		if(c[i]<0){
			c[i+1]--;//借位 
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
	//拆分每一位，然后逆序存放在数组中 
	for(int i = 0;i < la;i++) a[la - i - 1] = x[i] - '0';
	for(int i = 0;i < lb;i++) b[lb - i - 1] = y[i] - '0';
	//2. 模拟减法的过程
	 sub(c,a,b);
	 
	 for(int i = lc - 1;i >= 0;i--) cout << c[i];
	 
	return 0;
}
