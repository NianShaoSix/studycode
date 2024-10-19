# include<iostream>
using namespace std;
int main(){
	int n,x,y,res;
	cin>>n>>x>>y;
	if(y%x!=0){
		res=n-y/x-1;
	}
	else res=n-y/x;
	cout<<res<<endl;
	return 0;
}
