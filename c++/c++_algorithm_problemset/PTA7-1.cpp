#include<iostream>
using namespace std;
int length(int n){
	int len=0;
	while(n){
		n/=10;
		len++;
	}
	return len;
}
int ishuiwen(int n,int arr[],int len){
	int i=0;
	while(n){
		arr[i]=n%10;
		n/=10;
		i++;
	}
	int j=0;
	while(arr[j]==arr[len-j-1]&&j<len/2){
		j++;
	}
	if(j==(int)len/2) return 1;
	else if(j!=len/2) return 0;
}

int main(){
	int n;int arr[20];int arr2[20];
	while(cin>>n){
	
	arr2[0]=n;
	int len=length(n);int count=0;
	while(!ishuiwen(n,arr,len)){
		int a=arr[0];int b=arr[len-1];
		for(int i=1;i<len;i++){
			a=a*10+arr[i];
			b=b*10+arr[len-i-1];		
		}
		n=a+b;len=length(n);
		count++;arr2[count]=n;
	}
	cout<<count<<endl;
	cout<<arr2[0];
	for(int i=1;i<=count;i++){
		cout<<"--->"<<arr2[i];
	}
	cout<<endl;
	}

}
