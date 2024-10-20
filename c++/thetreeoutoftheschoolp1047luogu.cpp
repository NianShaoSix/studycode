#include<iostream>
using namespace std;
int main(){
	int l,m;
	cin>>l>>m;
	int arr[l+1];
	for(int i=0;i<l+1;i++){
		arr[i]=0;
	}
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		for(int j=x;j<=y;j++){
			arr[j]++;
		}
	}
	int count=0;
	for(int z=0;z<l+1;z++){
		if(arr[z]==0) count++;
	}
	cout<<count;
	return 0;
	
}
