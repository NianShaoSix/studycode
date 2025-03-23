#include <iostream>
#include <cmath>
using namespace std;
int n;
int main(){
	cin >> n;
	int a;
	for(int i = n;i >= 0;i--){
		cin >> a;
		if(a == 0) continue;
		//1.先输出符号
		if(a < 0) cout <<"-";
		else {
			if(i != n) cout<<"+";
		} 
		//2.处理数字
		a = abs(a); 
		if(a!=1||(a==1&&i==0)) cout <<a;
		//3.处理指数
		if(i == 0) continue;
		else if(i == 1) cout <<"x";
		else cout << "x^"<<i;
	}	
	return 0;
}
