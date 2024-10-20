#include<iostream>
using namespace std;
int main(){
	int arr[10];
	int h;
	for(int i=0;i<10;i++){
		cin>>arr[i];
	}
	cin>>h;
	int i=0;
	int count=0;
	for(;i<10;i++){
		if(arr[i]<=h+30) count++;
	}
	cout<<count;
	return 0;
}
