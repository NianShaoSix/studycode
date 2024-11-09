#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int head[n];	
	int qishi[m];
	for(int i=0;i<n;i++){
		cin>>head[i];
	}
	for(int j=0;j<m;j++){
		cin>>qishi[j];
	}
	sort(head,head+n);
	sort(qishi,qishi+m);
	int i=0,ans=0,j=0;
	while(i<n&&j<m){
		if(head[i]<=qishi[j]){
		
		ans+=qishi[j];
		i++;j++;
		}
		else j++;
	}
	if(i==n){
		cout<<ans;
	}
	else cout<<"you died!"<<endl;
	
	return 0;
	}
