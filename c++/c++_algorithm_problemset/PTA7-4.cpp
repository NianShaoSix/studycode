#include<iostream>
using namespace std;
bool ishuzhi(int a,int b){
	int res=1;
	int max=a>=b?a:b;
	int min=a<b?a:b;
	while(max%min){
		int temp;
		temp=min;
		min=max%min;
		max=temp;
	}
	res=min;
	return res==1?1:0;
}
int main(){
	int T,n;int count=0;
	cin>>T;int arr[T]={0};
	for(int i=0;i<T;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			int a,b;
			cin>>a>>b;
			if(ishuzhi(a,b)){
				count++;
			}
		}
		cout<<count;
}
}
