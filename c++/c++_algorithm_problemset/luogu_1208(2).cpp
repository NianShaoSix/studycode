#include<iostream>
using namespace std;
typedef struct NaiNong{
	int price;
	int number;
}NN;
int main(){
	int n,m; 
	cin>>n>>m;
	NN arr[m];
	for(int i=0;i<m;i++){
		cin>>arr[i].price>>arr[i].number;
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(arr[i].price>arr[j].price){
				NN temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	int k=0;int sum=0;
	while(n>0){
		if(n>arr[k].number){
			n-=arr[k].number;
			sum+=arr[k].number*arr[k].price;
			k++;
		}
		else {
		sum+=n*arr[k].price;
		break;}
	}
	cout<<sum;
	return 0;
}
