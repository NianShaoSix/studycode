#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n=100;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			for(int l=0;l<=n-i-j;l++){
				if(i*5+j*3+l/3==n&&i+j+l==n&&l%3==0){
					cout<<"����"<<setw(2)<<i<<"ֻ,"<<"ĸ��"<<setw(2)<<j<<"ֻ,"<<"С��"<<setw(2)<<l<<"ֻ"<<endl; 
				}
			}
		}
	}
	return 0;
}
