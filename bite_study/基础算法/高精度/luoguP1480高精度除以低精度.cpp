#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N],b,c[N];
int la,lc;


//高精度除以低精度模板  c = a/b
void sub(int c[], int a[],int b){
	long long t = 0;
	for(int i = la - 1;i >= 0; i--){
		//计算当前被除数
		t = t * 10 + a[i];
		c[i] = t/b;
		t%=b; 
	}
	//处理前导0
	while(lc > 1&& c[lc - 1] == 0) lc--;
	 
}

int main(){
	string x; cin >> x >>b;
	la = x.size();lc = la;
	
	for(int i = 0;i < la;i++) a[la - i -1] = x[i] - '0';
	
	//模拟除法过程 
	sub(c,a,b);
	
	for(int i = lc - 1;i >= 0;i--) cout <<c[i];
	
	return 0;
} 
