#include<iostream>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	if(a>=1&&b>=1&&b<=50000){
		long long res;
		res=a*b;
		cout<<res;
	}
	return 0;
}
