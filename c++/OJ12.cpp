#include<iostream>
#include<iomanip>
#define PI 3.14
using namespace std;
int main(){
	double r;
	cin>>r;
	double V;\
	V=4*1.0/3*PI*r*r*r;
	//V=4*PI*r*r*r/3;
	cout<<fixed<<setprecision(2)<<V<<endl;
	return 0;
}
