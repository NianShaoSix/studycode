#include<iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	int n=0;
	double res;
	while(res<=k){
		++n;
		res+=1.0/n;
	}
	cout<<n;
}
