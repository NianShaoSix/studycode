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
		//1.���������
		if(a < 0) cout <<"-";
		else {
			if(i != n) cout<<"+";
		} 
		//2.��������
		a = abs(a); 
		if(a!=1||(a==1&&i==0)) cout <<a;
		//3.����ָ��
		if(i == 0) continue;
		else if(i == 1) cout <<"x";
		else cout << "x^"<<i;
	}	
	return 0;
}
