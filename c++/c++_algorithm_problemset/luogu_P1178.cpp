#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int arr[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
	int n;int sum=0;
	cin>>n;
	int arr2[367]={0};
	for(int i=1;i<367;i++){
		arr2[i]=1;
	}
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		arr2[arr[x]+y]=0;
	}
	int res=0;
	for(int i=1;i<367;i++){
		if(arr2[i]) sum++;
		else sum=0;
		if(sum>res) res=sum;
	}
	cout<<round(res*3600*24*1.0/366);
	return 0;
}


