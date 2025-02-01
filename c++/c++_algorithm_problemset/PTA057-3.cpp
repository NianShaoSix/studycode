#include<iostream>
using namespace std;
int main(){
	int n,k,s;
	cin>>n>>k>>s;
	int x=0,y=0;
	int arr[291];
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(x>=175){
			if(y>=s){
				cnt++;
			}
			else if(arr[x]<k){
				arr[x]++;
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

