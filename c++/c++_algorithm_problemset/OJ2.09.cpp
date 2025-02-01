#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int count=0;
	switch(0){
		case 0:if(n%3==0) cout<<3<<" ";else count++;
		case 1: if(n%5==0) cout<<5<<" ";else count++;
		case 2: 
		if(n%7==0) cout<<7; else count++;break;
	}
	if(count==3) cout<<'n';
	return 0;
}
