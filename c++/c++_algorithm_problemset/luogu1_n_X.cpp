#include<iostream>
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	int count=0;
	for(int i=1;i<=n;i++){
		int j=i;
		while(j){
			if(j%10==x||j==x){
				count++;
			}
			j/=10;
		}
	}
	cout<<count;
}
