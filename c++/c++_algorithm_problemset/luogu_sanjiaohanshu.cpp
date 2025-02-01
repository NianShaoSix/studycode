#include<iostream>
using namespace std;
int gcd(int a,int b){
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int min=a,max=c;
	if(b<a&&b<c){
		min=b;
	}
	if(c<b&&c<a){
		min=c;
	}
	if(a>b&&a>c) max=a;
	if(b>a&&b>c) max=b;
/*	for(int i=min;i>0;i--){
		if(min%i==0&&max%i==0){
			min/=i;
			max/=i;
		}
	}
	} */
	int res=gcd(max,min);
	cout<<min/res<<'/'<<max/res;
}
