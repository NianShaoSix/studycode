#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	for(int i=1;i<=30;i++){
		if(6*i==30){
			a=i;
		}
	}
	for(int j=1;j<=20;j++){
		if(2*a+2*j==20){
			b=j;
		}
	} 
	for(int k=1;k<=17;k++){
		if(6*k+b==17){
			c=k;
		}
	}
	cout<<"鞋子"<<"="<<a<<endl;
	cout<<"机器"<<"="<<b<<endl;
	cout<<"水"<<"="<<c<<endl;
	cout<<"第4个式子得数为"; 
	cout<<a+(3*c+2*a+b)*c<<endl;
	return 0;
}
