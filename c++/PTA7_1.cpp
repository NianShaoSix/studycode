#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int res=0;
	for(int cnt_m=0;cnt_m<=n;cnt_m++){
		for(int cnt_w=0;cnt_w<=n-cnt_m;cnt_w++){
			for(int cnt_c=0;cnt_c<=n-cnt_m-cnt_w;cnt_c++){
				if(cnt_m*3+cnt_w*2+cnt_c/2==n&&cnt_m+cnt_w+cnt_c==n&&cnt_c%2==0){
					cout<<"men = "<<cnt_m<<", "<<"women = "<<cnt_w<<", "<<"child = "<<cnt_c<<endl;
					res++;
				}
				
			}
		}
	}
	if(!res) cout<<"None";
	return 0;
} 
