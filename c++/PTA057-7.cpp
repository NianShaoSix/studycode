#include <iostream>
using namespace std;
int arr[10],vis[10]={0};
	int n;
void f(int i, int n){
	if(i==n) {
	for(int j=0; j<n; j++){
		cout << arr[j] << ' ';
	}
	puts("");
	return ;
	}
	for(int k=1;k<=n;k++){
		if(!vis[k]) {
			arr[i]=k;
			vis[k]=1;
			f(i+1,n);
			vis[k]=0;
		}
	}
	return ;
}
int main(){

	cin >> n;
	f(0,n);
	return 0;
} 
