#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];
int ans;int n,c;
bool check(int x){
	//ÿ��ţ��֮������֮��ļ�����ٴ��ڵ���x
	 int cnt=1;int pre=a[1];
	 for(int i=2;i<=n;i++){
	 	if(a[i]-pre>=x){
	 		cnt++;
	 		pre = a[i];
		 }
	 }
	 if(cnt>=c){
	 	return true;
	 }
	 else return false;
}
int main(){

	cin >> n >> c;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	int l=0,r=a[n]-a[1]+1;
	while(l+1!=r){
		int mid=(l+r)/2;
		if(check(mid))
		l=mid;//���
		else
		r=mid; 
		
	}
	 cout << l << endl;
	return 0;
} 
