#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	double res=b*1.0/a;
	cout<<fixed<<setprecision(3)<<res*100<<'%'<<endl;
	return 0;
	
}
