#include<iostream>
using namespace std;
int main(){
	int dis;
	cin>>dis;
	double time1,time2;
	time1=27+23+dis*1.0/3.0;
	time2=dis*1.0/1.2;
	if(time1<time2) cout<<"Bike";
	else if(time1==time2) cout<<"All";
	else cout<<"Walk";
	return 0;
}
