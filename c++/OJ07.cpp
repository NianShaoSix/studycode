#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double x,a,b,c,d;
	cin>>x>>a>>b>>c>>d;
	double res;
	res=a*x*x*x+b*x*x+c*x+d;
	cout<<fixed<<setprcision(7)<<res<<endl;
	return 0;
}
