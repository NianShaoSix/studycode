#include <iostream>

using namespace std;
int n;
const int N = 1e4 + 10;
int a[N],b[N];

int check(int x){
	a[1] = x;
	for(int i = 2;i <= n+1;i++){
		a[i] = b[i-1] - a[i-1] - a[i-2];
		if(a[i] < 0||a[i] > 1) return 0;
	}
	if(a[n+1]==0) return 1;
	else return 0;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >>b[i];
	}
	int ret = 0;
	ret+=check(0);//a[1]²»·Å
	ret+=check(1);//a[2]·Å 
	cout <<ret;
	return 0; 
}


 
