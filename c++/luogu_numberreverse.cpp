#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[11];
	int i=0;
	while(n){
		
		arr[i]=n%10;
		n/=10;
		i++;
	}
	int res=0;
	for(int j=0;j<i;j++){
		res=res*10+arr[j];
	}
	cout<<res;
	}
