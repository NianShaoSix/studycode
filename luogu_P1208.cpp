#include<iostream>
using namespace std;
struct nairong{
	int number;
	int price;
};
int main(){
	int n,m;
	cin>>n>>m;
	int sum,allprice;
	struct nairong nr[m];
	for(int i=0;i<m;i++){
		cin>>nr[i].price>>nr[i].number;
	}
	int len=sizeof(nr)/sizeof(nr[0]);
    for(int i=0;i<len;i++){
        for(int j=0;j<n-i-1;j++){
            if(nr[j].price>nr[j+1].price){
                struct nairong temp=nr[j];
                nr[j]=nr[j+1];
                nr[j+1]=temp;
            }
        }
    }
    while(n>0){
        if(nr[0].number<n){
            sum+=nr[0].number*nr[0].price;
            n-=nr[0].number;
            for(int i=0;i<n;i++){
                nr[i]=nr[i+1];
            }
        }
        else{
            sum+=nr[0].price*n;
            break;
        }

    }
        cout<<sum;
}