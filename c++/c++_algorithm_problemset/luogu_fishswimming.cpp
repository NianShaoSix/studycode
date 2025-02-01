#include<iostream>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int time1,time2;
	time1=a*60+b;
	time2=c*60+d;
	cout<<(time2-time1)/60<<' '<<(time2-time1)%60;
}
