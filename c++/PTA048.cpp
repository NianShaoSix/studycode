#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int arr[3];
	int cnt=0;
	for(int i=0;i<3;i++){
		cin>>arr[i];
	}
	sort(arr,arr+3);
	int left=arr[0];
	int right=arr[2];
	int mid=arr[1];
	if(left+right>=2*mid){
		while(mid<right-1){
		left=mid;
		mid++;
		cnt++;}
	}
	else if(left+right<2*mid){
	
	while(mid>left+1){
		right=mid;
		mid--;
		cnt++;
	}
	}
	cout<<cnt<<endl;
	return 0;
}
