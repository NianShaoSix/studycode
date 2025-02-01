#include<iostream>
using namespace std;
struct Ditan{
	int a,b,g,k;
};
int main(){
	int n;
	cin>>n;
	Ditan ditan[n];
	for(int i=0;i<n;i++){
		cin>>ditan[i].a>>ditan[i].b>>ditan[i].g>>ditan[i].k;
	}
	int x,y;
	cin>>x>>y;
	int j=n-1;
	while(x<ditan[j].a||x>ditan[j].a+ditan[j].g||y<ditan[j].b||y>ditan[j].b+ditan[j].k&&j>0){
		--j;
	}
	if(j>=0) cout<<j+1;
	else cout<<-1;
}
