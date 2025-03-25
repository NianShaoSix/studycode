#include <iostream>
//枚举顺序对算法的影响 
using namespace std;

const int N = 1e5 + 10;
int n;
int x[N],y[N],h[N],w[N];
int a,b,g,k;
int flag;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >>x[i]>>y[i]>>w[i]>>h[i];
	}
	int px,py;
	cin >> px >>py;
	for(int i = n;i >= 1;i--){
		if(px>=x[i]&&px<=x[i]+w[i]&&py>=y[i]&&py<=y[i]+h[i]){
			flag = 1;
			cout <<i;
			break;
		}
	}
	if(!flag) cout <<"-1";
	return 0;
}
