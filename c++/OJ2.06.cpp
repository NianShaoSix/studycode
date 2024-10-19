#include<iostream>
using namespace std;
int main(){
	 int n;
	 cin>>n;
	 int count=0;
	 while(n/10){
	 	count++;
		n/=10;
	 }
	 if(count==1){
	 	cout<<1;
	 }
	 else cout<<0;
	 return 0;
}
