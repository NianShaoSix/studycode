#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N;
	long C;
	int count=0;
	cin>>N>>C;
	long long arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	sort(arr,arr+N);
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(arr[j]-arr[i]==C) count++;
		}
	}
	cout<<count;
}
