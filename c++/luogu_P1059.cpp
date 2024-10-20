#include<iostream>

using namespace std;
int main(){
	int N,x;
	cin>>N;
	int bus[1001]={0};int sum=0;
	for(int i=0;i<N;i++){
	cin>>x;
	if(bus[x]) continue;
	else {
		bus[x]++;
		sum++;
		}
	}
	cout<<sum<<endl; 
	for(int i=0;i<1001;i++){
		if(bus[i]) cout<<i<<' ';
	}
	return 0;
}
