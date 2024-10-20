#include<iostream>
using namespace std;
int main(){
	int ts,tas,day,sum,max;
	for(int i=0;i<7;i++){
	cin>>ts>>tas;
	sum=ts+tas;
	if(sum>8&&sum>max){
		max=sum;day=i+1;
	}
	}
	cout<<day;
	return 0;
}
