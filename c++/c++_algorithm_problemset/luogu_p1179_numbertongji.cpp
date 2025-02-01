#include<iostream>
using namespace std;
int main(){
	int L,R;
	int count=0;
	cin>>L>>R;
	for(int i=L;i<=R;i++){
		int tmp=i;
		while(tmp){
			if(tmp%10==2) count++;
			tmp/=10;
		}
	}
	cout<<count;
	return 0;
}
