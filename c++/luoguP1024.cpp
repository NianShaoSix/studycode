#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
double fx(double a,double b,double c,double d,double x){
	return a*x*x*x+b*x*x+c*x+d;
}
int main(){
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	double left,mid,right;
	int cnt=0;
	double arr[3];
	for(int i=-100;i<=100;i++){
		if(fx(a,b,c,d,i)==0){
			arr[cnt]=i;
			cnt++;
		}
	}
	for(int j=-100;j<100;j++){	
		if(fx(a,b,c,d,j)*fx(a,b,c,d,j+1)<0){
				left=j;
				right=j+1;
				mid=(left+right)/2;
			while(right-left>0.001){
			if(fx(a,b,c,d,mid)*fx(a,b,c,d,left)<0){
				right=mid;
				mid=(right+left)/2;	
			}
			if(fx(a,b,c,d,mid)*fx(a,b,c,d,right)<0){
				left=mid;
				mid=(right+left)/2;
			} 
		}
		arr[cnt]=(left+right)/2;
			cnt++;
	}
	if(cnt==3) break;
}
	sort(arr,arr+3);
	for(int k=0;k<3;k++){
		cout<<fixed<<setprecision(2)<<arr[k]<<' ';
	}
	return 0;
}
