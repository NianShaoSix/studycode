#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double a,b;
	cin>>a>>b;
	int k=(int)(a/b);
	double r=a-k*b;
	cout<<r<<endl;
	return 0;
}
