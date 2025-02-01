#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	float a,b;
	cin>>a>>b;
	float c=1/(1/a+1/b);
	cout<<fixed<<setprecision(2)<<c<<endl;
	return 0;
}
