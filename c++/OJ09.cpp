#include<iostream>
#include<iomanip>
#define PI 3.14159
using namespace std;
int main(){
	double r;
	cin>>r;
	double d,c,s;
	d=2*r;
	c=d*PI;
	s=PI*r*r;
	cout<<fixed<<setprecision(4)<<d<<' '<<c<<' '<<s<<endl;
	return 0;
}
