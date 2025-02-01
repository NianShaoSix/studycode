#include<iostream>
#include<iomanip>
using namespace std;
typedef struct golden{
	int weight,value;
}G; 
int main(){
	int N,T;
	cin>>N>>T;
	G g[N];
	for(int i=0;i<N;i++){
		cin>>g[i].weight>>g[i].value;
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			G temp;
			if(g[i].value*1.0/g[i].weight<g[j].value*1.0/g[j].weight){
				temp=g[i];
				g[i]=g[j];
				g[j]=temp;
			}
		}
	}
	double sum=0;int k=0;
	while(T>0&&k<N){
		
		if(T>g[k].weight) {
			T-=g[k].weight;
			sum+=g[k].value;
			k++;
		}
		else {
			sum+=g[k].value*1.0/g[k].weight*T;
				T=0;	
		}
		
	}
	cout<<fixed<<setprecision(2)<<sum;
}
