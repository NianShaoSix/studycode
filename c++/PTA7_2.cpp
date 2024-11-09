#include<iostream>
using namespace std;
int main(){
	for(int i=0;i<=98;i++){
		for(int j=0;j<=98-i;j++){
			if(2*i+4*j==386&&i+j==98){
				cout<<"chicken:"<<i<<endl;
				cout<<"rabbit:"<<j<<endl;
			}
		}
	}
	return 0;
}
