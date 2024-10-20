#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int x,a,y,b;
	cin>>x>>a>>y>>b;
	double gap=abs(x*a-y*b)*1.0/abs(a-b);
	cout<<fixed<<setprecision(2)<<round(gap*100)/100.0;
}
