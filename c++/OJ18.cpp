#include<iostream>
using namespace std;
int main(){
	int a1,a2,n;
	cin>>a1>>a2>>n;
	int q=a2-a1;
	int an=a1+q*(n-1);
	cout<<an;
	return 0;
}
