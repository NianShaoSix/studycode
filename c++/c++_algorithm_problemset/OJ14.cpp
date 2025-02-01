#include<iostream>
#define PI 3.14159
using namespace std;
int main(){
	int r,h;
	cin>>h>>r;
	double v;
	v=h*PI*r*r;
	double n;
	n=20000/v;
	int x;
	x=n>(int)n?((int)n+1):(int)n;
	cout<<x<<endl;
	return 0;
}
