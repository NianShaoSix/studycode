#include <iostream>
#include <string>
using namespace std;
string s1,s2;
const int N = 1e6 + 10;
int a[N],b[N],c[N];
int sum[N];
int main(){
	cin >> s1 >> s2;
	int len1 = s1.size(),len2 = s2.size();
	for(int i = 1;i <=len1;i++){
		a[i] = s1[len1-i] - '0';
	}
	for(int j = 1;j <= len2;j++){
		b[j] = s2[len2-j] - '0';
	}
	int len3 = max(len1,len2);
	for(int i = 1;i<= len3 + 1;i++){
		sum[i]=c[i]+a[i]+b[i];
		c[i+1] = sum[i]/10;
		sum[i] = sum[i]%10; 
	}
	if(sum[len3 + 1] != 0) cout << sum[len3 + 1];
	for(int i = len3;i >=1;i--){
		cout <<sum[i];
	}
	return 0;
} 
