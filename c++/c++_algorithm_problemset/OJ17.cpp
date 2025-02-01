#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float calculateLength(float x1,float y1,float x2,float y2 );
int main(){
	float x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	float a,b,c;
	a=calculateLength(x1,y1,x2,y2);
	b=calculateLength(x2,y2,x3,y3);
	c=calculateLength(x3,y3,x1,y1);
	float s=(a+b+c)/2;
	float res;
	res=sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<fixed<<setprecision(2)<<res;
	return 0;
}
float calculateLength(float x1,float y1,float x2,float y2 ){
	float l=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return l;
}
