#include<iostream>
using namespace std;
int fn(int n,int k){
	int res=k;int i=1;
	while(--n){
		res=res+i*n;
		i++;
	}
	return res;
}

int main(){
	int T;
	cin>>T;int arr[T];
	for(int i=0;i<T;i++){
		int n,k;
		cin>>n;
		cin>>k;
		arr[i]=fn(n,k);
	}
	for(int l=0;l<T;l++){
		cout<<arr[l]<<endl;
	}


}
