#include<iostream>
using namespace std;
int main(){
	long int N;
	cin>>N;
	if(N>0){
		cout<<"positive";
	}
	else if(N==0){
		cout<<"zero";
	}
	else cout<<"negative";
	return 0;
}
