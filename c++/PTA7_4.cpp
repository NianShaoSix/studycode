#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n=100;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			for(int l=0;l<=n-i-j;l++){
				if(i*5+j*3+l/3==n&&i+j+l==n&&l%3==0){
					cout<<"公鸡"<<setw(2)<<i<<"只,"<<"母鸡"<<setw(2)<<j<<"只,"<<"小鸡"<<setw(2)<<l<<"只"<<endl; 
				}
			}
		}
	}
	return 0;
}
