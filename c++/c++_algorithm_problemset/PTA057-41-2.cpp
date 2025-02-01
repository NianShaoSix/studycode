#include<iostream>
using namespace std;
int main(){
	int arr[13]={0};
	arr[0]=1;
	arr[1]=1;
	arr[2]=1;
	int i=0;
	int n;
	cin>>n;
	if(n<=0){
		cout<<"请输入几个月的整数值:"<<endl;
		cout<<"num="<<0;
	}
	
	else{
	for(i=3;i<=n;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	cout<<"请输入几个月的整数值:"<<endl;
	cout<<"num="<<arr[n];
	}
	return 0;
}
