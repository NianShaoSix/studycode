#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==1||n==3||n==5){
		cout<<"NO";
	}
	else if(n==2||n==4||n==6||n==7){
		cout<<"YES";
	}
	else cout<<"illigal input";
	return 0;
}
